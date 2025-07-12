import { useState } from 'react';
import DynamicComponent from './DynamicComponent';
import './App.css';

function App() {
  const [count, setCount] = useState(0);
  return (
    <div className="App">
      <h1>Props & State Experiment</h1>
      <DynamicComponent count={count} />
      <button onClick={() => setCount(count + 1)}>Increment</button>
      <button onClick={() => setCount(count - 1)}>Decrement</button>
      <button onClick={() => setCount(0)}>Reset</button>
    </div>
  );
}

export default App;
