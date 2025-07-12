'use client';

import { useState, useEffect } from 'react';
import Head from 'next/head';
import { api } from '../../utils/api';
import TaskList from '../../components/TaskList';
import TaskForm from '../../components/TaskForm';

export default function HomePage() {
  const [tasks, setTasks] = useState([]);
  const [loading, setLoading] = useState(true);

  // Fetch tasks on mount
  useEffect(() => {
    fetchTasks();
  }, []);

  const fetchTasks = async () => {
    try {
      setLoading(true);
      const response = await api.get('/tasks');
      setTasks(response.data);
    } catch (err) {
      console.error('Error fetching tasks:', err);
    } finally {
      setLoading(false);
    }
  };

  const handleCreate = async (data) => {
    try {
      await api.post('/tasks', data);
      fetchTasks();
    } catch (err) {
      console.error('Error creating task:', err);
    }
  };

  const handleDelete = async (id) => {
    try {
      await api.delete(`/tasks/${id}`);
      setTasks((prev) => prev.filter((t) => t.id !== id));
    } catch (err) {
      console.error('Error deleting task:', err);
    }
  };

  return (
    <main className="max-w-2xl mx-auto p-6">
      <Head>
        <title>Task Manager</title>
      </Head>
      <h1 className="text-2xl font-bold mb-4">Task Manager</h1>

      <section className="mb-8">
        <h2 className="text-xl font-semibold mb-2">Create New Task</h2>
        <TaskForm onSubmit={handleCreate} />
      </section>

      <section>
        <h2 className="text-xl font-semibold mb-2">All Tasks</h2>
        {loading ? (
          <p>Loading...</p>
        ) : tasks.length === 0 ? (
          <p>No tasks found.</p>
        ) : (
          <TaskList tasks={tasks} onDelete={handleDelete} />
        )}
      </section>
    </main>
  );
}
