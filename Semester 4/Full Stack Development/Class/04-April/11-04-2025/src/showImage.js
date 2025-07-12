import React, { useEffect, useState } from 'react'

export default function ShowImage() {

    const [counter, setCounter] = useState(0);

    function increment() {
        setCounter(counter+1)
    }

    function decrement() {
        setCounter(counter-1)
    }

    useEffect(() => {
    }, [counter])

    let randomNum = Math.floor(Math.random() * 100);
    let imageUrl = `https://picsum.photos/id/${randomNum}/720/360`;
    return (

        <>
            {/* {
                randomNum >= 5 ?
                (<div><img src={imageUrl} alt="Random"/>
                <p>Image ID: {randomNum}</p></div>)
                : <p>Image ID: {randomNum} is less than 5</p>
            } */}


            <div style={{
                display: "flex",
                flexDirection: "column",
                alignItems: "center",
                justifyContent: "center",
                height: "100vh",
            }}>
                <img src={imageUrl} alt="Random" style={
                    { border: "2px solid black", borderRadius: "10px", width: "720px", height: "360px", marginTop: "10px" }
                } />
                <p><b>Image ID:</b> {randomNum}</p>

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

                <p style={{ fontSize: "20px" }}>Counter: {counter}</p>
            </div>
        </>
    )
}
