import React from 'react'
import { Formik, Form, Field, ErrorMessage } from 'formik'
import * as Yup from 'yup'
import axios from 'axios'
import { useNavigate } from 'react-router-dom'
import { AuthContext } from '../helpers/AuthContext'

function CreatePost() {

    const { authState } = React.useContext(AuthContext);

    const navigate = useNavigate();

    const initialValues = {
        title: '',
        content: '',
    }

    const validationSchema = Yup.object({
        title: Yup.string().required(),
        content: Yup.string().required(),
    })
    
    const onSubmit = (data) => {

        data.username = authState.username;
        axios.post('http://localhost:3001/posts', data,
            {
                headers: {
                    accessToken: localStorage.getItem('accessToken')
                }
            }
        ).then((res) => {
            if(res.data.error) {
                alert(res.data.error)
            }
            else{
                alert('Post created');
                navigate('/');
            }
        })
    }

    return (
        <div className='createPost'>

            <Formik initialValues={initialValues} onSubmit={onSubmit} validationSchema={validationSchema}>
                <Form id='createPostForm'>

                    <label className='form-label'>Title: </label>
                    <ErrorMessage name='title' component='span' className='error-span' />
                    <Field type='text' name='title' placeholder='Ex: Title...' />
                    <label className='form-label'>Content: </label>
                    <ErrorMessage name='content' component='span' className='error-span' />
                    <Field as='textarea' name='content' placeholder='Ex: Content...' />

                    <button type='submit'>Create Post</button>
                </Form>
            </Formik>

        </div>
    )
}

export default CreatePost
