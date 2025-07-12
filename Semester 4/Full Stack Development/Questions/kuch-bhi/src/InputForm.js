import {useState} from 'react';

export default function InputForm( {validator, onSubmit, label} ){
    const [value, setValue] = useState('');
    const [error, setError] = useState('');

    const handleChange = (e) => {
        setValue(e.target.value);
        setError('');
    }

    const handleSubmit = (e) => {
        e.preventDefault();
        const isValid = validator(value);
        if(isValid === true) {
            onSubmit(value);
            setValue('');
        }
        else {
            setError(isValid);
        }
    }

    return (
        <form onSubmit={handleSubmit}>
            <label> {label}: </label>
            <input type='text' value={value} onChange={handleChange} />
            {error && <span style={{color: 'red'}}> {error} </span>}
            <br />
            <button type='submit'> Submit </button>
        </form>
    )
}