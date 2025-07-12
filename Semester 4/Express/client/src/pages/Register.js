import React from 'react'
import { Formik, Form, Field, ErrorMessage } from 'formik'
import * as Yup from 'yup'
import axios from 'axios'
import { useNavigate } from 'react-router-dom';

function Register() {

    const navigate = useNavigate();

    const initialValues = {
        username: '',
        email: '',
        password: ''
    }

    const validationSchema = Yup.object({
        username: Yup.string().min(3).max(15).required(),
        password: Yup.string().min(8).max(20).required()
    })

    const registerUser = (data) => {
        axios.post('http://localhost:3001/auth/register', data).then(() => {
            alert('User registered successfully');
            navigate('/login');
        })
    }

  return (
    <div className='register'>
        <h1>Register</h1>
        <Formik
            initialValues={initialValues}
            validationSchema={validationSchema}
            onSubmit={registerUser}
        >
            <Form>
            <label htmlFor='username'>Username</label>
            <Field name='username' type='text' />
            <ErrorMessage name='username' />
    
            <label htmlFor='password'>Password</label>
            <Field name='password' type='password' />
            <ErrorMessage name='password' />
    
            <button type='submit'>Register</button>
            </Form>
        </Formik>
    </div>
  )
}

export default Register
