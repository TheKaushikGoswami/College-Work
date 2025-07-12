import imageCompression from 'browser-image-compression';
import './App.css';
import { useState } from 'react';

function App() {

  const [imageSize, setImageSize] = useState(null);
  const [compressedImage, setCompressedImage] = useState(null);

  const handleImageUpload = async (event) => {
    const file = event.target.files[0];
    if (!file) {
      console.error("No file selected");
      return;
    }

    const options = {
      maxSizeMB: 1,
      maxWidthOrHeight: 1920,
      useWebWorker: true
    };

    try {
      const compressedFile = await imageCompression(file, options);
      setImageSize(file.size);
      setCompressedImage(compressedFile);
    } catch (error) {
      console.error("Error during image compression:", error);
    }
  }

  const displayImage = () => {
    if (!compressedImage) {
      console.error("No compressed image available");
      return;
    }

    const imgElement = document.getElementById("compressedImage");

    const reader = new FileReader();
    reader.onload = (e) => {
      imgElement.src = e.target.result;
    };

    reader.readAsDataURL(compressedImage);
    imgElement.onload = () => {
      URL.revokeObjectURL(imgElement.src);
    };

    const container = document.getElementById("compressedImageContainer");
    container.style.display = "block";
    container.style.border = "1px solid #ccc";
  }

  return (
    <>
      <div style={{
        display: "flex",
        flexDirection: "column",
        alignItems: "center",
        justifyContent: "center",
      }}>
        <h1>Image Compression</h1>
        <input type="file" accept="image/*" style={{
          margin: "10px",
          padding: "10px",
          borderRadius: "5px",
          cursor: "pointer"
        }} onChange={handleImageUpload} />

        <button style={
          {
            margin: "10px",
            padding: "10px",
            borderRadius: "5px",
            cursor: "pointer"
          }
        } onClick={displayImage}>Compress Image</button>

        <div id='compressedImageContainer' style={{
          textAlign: "center",
          marginTop: "20px",
          border: "1px solid #ccc",
          padding: "20px",
          display: "none",
        }}>

          <h2>Compressed Image</h2>
          <img id="compressedImage" alt="Compressed" style={{
            maxWidth: "100%",
            maxHeight: "400px",
          }} />
          {compressedImage && (
            <>
            <p style={{ fontSize: "20px" }}>
              <strong>Original Image Size:</strong> {(imageSize / 1024 / 1024).toFixed(2)} MB
              <br />
              <strong>Compressed Image Size:</strong> {(compressedImage.size / 1024 / 1024).toFixed(2)} MB
            </p>

            <button style={{
              margin: "10px",
              padding: "10px",
              borderRadius: "5px",
              cursor: "pointer"
            }} onClick={() => {
              const link = document.createElement('a');
              link.href = URL.createObjectURL(compressedImage);
              link.download = compressedImage.name;
              document.body.appendChild(link);
              link.click();
              document.body.removeChild(link);
            }}>Download Compressed Image</button>
            </>

          )}

        </div>

      </div>
    </>
  );
}

export default App;
