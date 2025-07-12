import { useState, useEffect } from 'react';

export default function TaskForm({ initialData = {}, onSubmit }) {
    const [title, setTitle] = useState(initialData.title || '');
    const [completed, setCompleted] = useState(initialData.completed || false);

    useEffect(() => {
        if (initialData && initialData.id !== undefined) {
            setTitle(initialData.title || '');
            setCompleted(initialData.completed || false);
        }
    }, [initialData]);

    const handleSubmit = (e) => {
        e.preventDefault();
        if (!title.trim()) {
            alert('Title is required');
            return;
        }
        onSubmit({ title: title.trim(), completed });
        // If this is a “create” (no initialData.id), clear the form:
        if (!initialData.id) {
            setTitle('');
            setCompleted(false);
        }
    };

    return (
        <form onSubmit={handleSubmit} className="space-y-4">
            <div>
                <label className="block text-sm font-medium text-gray-700">
                    Title
                </label>
                <input
                    type="text"
                    value={title}
                    onChange={(e) => setTitle(e.target.value)}
                    className="mt-1 block w-full border-gray-300 rounded-md shadow-sm"
                />
            </div>
            <div className="flex items-center">
                <input
                    id="completed"
                    type="checkbox"
                    checked={completed}
                    onChange={(e) => setCompleted(e.target.checked)}
                    className="h-4 w-4 text-blue-600 border-gray-300 rounded"
                />
                <label htmlFor="completed" className="ml-2 block text-sm text-gray-700">
                    Completed
                </label>
            </div>
            <button
                type="submit"
                className="px-4 py-2 bg-green-500 text-white rounded hover:bg-green-600"
            >
                {initialData.id ? 'Update Task' : 'Create Task'}
            </button>
        </form>
    );
}
