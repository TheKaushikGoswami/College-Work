import './App.css';
import { useEffect, useMemo, useState } from 'react';
// import TraditionalDOM from './TraditionalDOM';
// import ReactDOM from './ReactDOM';

function App() {

  // const [count, setCount] = useState(0);
  const [num, setNum] = useState(0);

  const factorial = useMemo(() => {
    console.log("Calculating factorial...");
    let result = 1;
    for (let i = 1; i <= num; i++) {
      result *= i;
    }
    return result;
  }, [num]);

  return (
    <div style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', marginTop: '40px' }}>
      <h2 style={{ color: '#2c3e50', fontWeight: 'bold', marginBottom: '20px' }}>
        Factorial of {num} is {factorial}
      </h2>
      <button
        style={{
          padding: '10px 20px',
          backgroundColor: '#3498db',
          color: '#fff',
          border: 'none',
          borderRadius: '5px',
          cursor: 'pointer',
          fontSize: '16px'
        }}
        onClick={() => setNum(num + 1)}
      >
        Increase & Re-render
      </button>
    </div>
  );
}

export default App;
