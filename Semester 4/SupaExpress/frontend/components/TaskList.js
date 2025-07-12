// frontend/components/TaskList.js

import Link from 'next/link';

export default function TaskList({ tasks, onDelete }) {
  return (
    <ul className="space-y-2">
      {tasks.map((task) => (
        <li
          key={task.id}
          className="flex items-center justify-between p-2 bg-gray-100 rounded"
        >
          <div>
            <span className="font-medium">{task.title}</span>
            <span className="ml-2 text-sm text-gray-500">
              {task.completed ? '(✔️)' : '(❌)'}
            </span>
          </div>
          <div className="space-x-2">
            <Link href={`/edit/${task.id}`}>
              <button className="px-2 py-1 text-sm bg-blue-500 text-white rounded">
                Edit
              </button>
            </Link>
            <button
              onClick={() => onDelete(task.id)}
              className="px-2 py-1 text-sm bg-red-500 text-white rounded"
            >
              Delete
            </button>
          </div>
        </li>
      ))}
    </ul>
  );
}
