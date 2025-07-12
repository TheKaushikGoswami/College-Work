import { useEffect } from 'react'

export default function TraditionalDOM() {
    useEffect(() => {
        document.getElementById('updateBtn').addEventListener('click', () => {
            document.getElementById('counter').textContent = parseInt(document.getElementById('counter').textContent) + 1
        });
    }, [])
    return (
        <div>
            <h2>Traditional DOM Manipulation</h2>
            <p id='counter'>0</p>
            <button id='updateBtn'>Update Counter</button>
        </div>
    )
}
