// frontend/src/app/edit/[id]/page.js
'use client';

import { useState, useEffect } from 'react';
import { useRouter, usePathname } from 'next/navigation';
import { api } from '../../../../utils/api';
import TaskForm from '../../../../components/TaskForm';

export default function EditTaskPage() {
  const router = useRouter();
  const pathname = usePathname(); // e.g. "/edit/3"
  const id = pathname.split('/').pop(); // "3"
  const [initialData, setInitialData] = useState(null);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    if (!id) return;
    fetchTask(id);
  }, [id]);

  const fetchTask = async (taskId) => {
    try {
      setLoading(true);
      const response = await api.get(`/tasks/${taskId}`);
      setInitialData(response.data);
    } catch (err) {
      console.error('Error fetching task:', err);
    } finally {
      setLoading(false);
    }
  };

  const handleUpdate = async (data) => {
    try {
      await api.put(`/tasks/${id}`, data);
      router.push('/');
    } catch (err) {
      console.error('Error updating task:', err);
    }
  };

  if (loading) return <p>Loading task...</p>;
  if (!initialData) return <p>Task not found.</p>;

  return (
    <main className="max-w-2xl mx-auto p-6">
      <h1 className="text-2xl font-bold mb-4">Edit Task #{initialData.id}</h1>
      <TaskForm initialData={initialData} onSubmit={handleUpdate} />
    </main>
  );
}
