import './App.css';
import React, { useState } from 'react';

function App() {
  const [name, setName] = useState("");
  const [image, setImage] = useState(null);
  return (
    <div className="App" style={{display: "flex", flexDirection: "column", alignItems: "center", justifyContent: "center", height: "100vh"}}>

      <input type="text" placeholder="Enter your name" style={{width: "300px", height: "30px", borderRadius: "5px", border: "1px solid black", marginTop: "10px", padding: "5px"}}
      onChange={
        (event) => {
          setName(event.target.value);
          console.log(name);
        }
      }/>

      <input type="file" accept="image/*" style={{width: "300px", height: "30px", borderRadius: "5px", border: "1px solid black", marginTop: "10px", padding: "5px", textAlignLast: "center"}} onChange={
        (event) => {
          const file = event.target.files[0];
          const reader = new FileReader();
          reader.onloadend = () => {
            setImage(reader.result);
          };
          if (file) {
            reader.readAsDataURL(file);
          }
        }
      }/>
      <button style={{width: "300px", height: "30px", borderRadius: "5px", border: "1px solid black", marginTop: "10px", padding: "5px", textAlign: "center"}}
      onClick={
        (event) => {
          event.preventDefault();
          console.log("Submitted");
          console.log(name);
          console.log(image);
        }
      }>Submit</button>
    </div>
  );
}

export default App;