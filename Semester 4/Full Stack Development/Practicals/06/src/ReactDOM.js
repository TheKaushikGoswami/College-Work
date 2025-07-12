import React from 'react'

export default function ReactDOM() {
    const [count, setCount] = React.useState(0);

    return (
        <div>
            <h2> React Virtual DOM</h2>
            <p>{count}</p>
            <button onClick={() => setCount(count + 1)}> Increment </button>
        </div>
    )
}
