import InputForm from "./InputForm";
export default function App() {
  
  const validateName = (name) => {
    if (!name) return 'Name cannot be empty';
    if (name.length < 3) return 'Name must be at least 3 characters long';
    return true;
  }

  const handleNameSubmit = (name) => {
    console.log('Submitted Name:', name);
    alert(`Name submitted: ${name}`);
  }

  return (
    <>
      <h1> Input Validation Example </h1>
      <InputForm label="Name" validator={validateName} onSubmit={handleNameSubmit}/>
    </>
  );
}