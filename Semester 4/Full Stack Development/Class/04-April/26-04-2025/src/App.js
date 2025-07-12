import './App.css';
import { useState, useEffect } from 'react';

function App() {

  const [counter, setCounter] = useState(0);
  const [mydata, setData] = useState([]);

  useEffect(() => {
    fetch('https://jsonplaceholder.typicode.com/posts')
      .then(data => {
        return data.json()
      })
      .then(data => {
        // console.log(data);
        setData(data);
      })
  }, [])

  function increment() {
    setCounter(counter + 1)
  }

  function decrement() {
    setCounter(counter - 1)
  }

  useEffect(() => {
    console.log(`Counter updated: ${counter}`);

    return () => {
      console.log(`Counter cleanup for: ${counter}`);
    }
  }, [counter])

  return (
    <>
      <div style={{
        display: "flex",
        flexDirection: "column",
        alignItems: "center",
        justifyContent: "center"
      }}>

        <div style={{
          textAlign: "center",
        }}>
          <button onClick={increment} style={{
            margin: "10px",
            padding: "10px",
            backgroundColor: "blue",
            color: "white",
            border: "none",
            borderRadius: "5px",
            cursor: "pointer"
          }}>Increment</button>

          <button onClick={decrement} style={{
            margin: "10px",
            padding: "10px",
            backgroundColor: "red",
            color: "white",
            border: "none",
            borderRadius: "5px",
            cursor: "pointer"
          }}>Decrement</button>
          <p style={{ fontSize: "20px" }}><strong>Counter:</strong> {counter}</p>
        </div>

        <div style={{
          display: "flex",
          flexWrap: "wrap",
          justifyContent: "center",
          gap: "20px",
        }}>
          {mydata.slice(0, 100).map((item) => {
            return (
              <div key={item.id} style={{
                border: "2px solid black",
                borderRadius: "10px",
                width: "200px",
                height: "300px",
                overflow: "hidden",
                textAlign: "center"
              }}>
                
                <h3 style={{ fontSize: "18px", margin: "10px" }}>{item.title}</h3>

                <p style={{ fontSize: "14px", margin: "10px" }}>{item.body}</p>
              </div>
            )
          })}
        </div>

      </div>
    </>
  );
}

export default App;
