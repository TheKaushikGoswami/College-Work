import { useState } from "react";

export default function ToDoList() {

    const [tasks, setTasks] = useState([]);
    const [task, setTask] = useState("");

    const addTask = () => {
        if (task.trim()) {
            setTasks([...tasks, task]);
            setTask("");
        }
    };

    const removeTask = (index) => {
        const newTasks = tasks.filter((_, i) => i !== index);
        setTasks(newTasks);
    }

    return (
        <div>
            <h1>
                Simple To Do List
            </h1>
            <input type="text" value={task} onChange={(e) => setTask(e.target.value)} placeholder="Enter a task" />

            <button onClick={addTask}>Add</button>

            <ul style={{ listStyleType: "none", padding: "10px"}}>
                {tasks.map((t, index) => (
                    
                <li key={index} style={{ display: "flex", justifyContent: "space-between", alignItems: "center", marginBottom: "10px", padding: "10px", border: "1px solid #ccc", borderRadius: "5px"}}>
                    {t}
                    <button onClick={() => removeTask(index)}>Remove</button>
                </li>
                ))}
            </ul>
        </div>
    )
}
