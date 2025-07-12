import React from 'react'
import axios from 'axios'
import { useNavigate } from 'react-router-dom'
import { AuthContext } from '../helpers/AuthContext'

function Login() {

  const navigate = useNavigate()
  const { setAuthState } = React.useContext(AuthContext)

  const [username, setUsername] = React.useState('');
  const [password, setPassword] = React.useState('');

  const loginUser = () => {
    const data = { username: username, password: password }
    axios.post('http://localhost:3001/auth/login', data).then((response) => {
      localStorage.setItem('accessToken', response.data)
      if(response.data.error) {
        alert(response.data.error)
      }
      else{
        localStorage.setItem('accessToken', response.data.token)
        setAuthState(
          {
            username: response.data.username,
            id: response.data.id,
            status: true
          }
        )
        navigate('/')
      }
    })
  }

  return (
    <div className='login'>
      
      <h1>Login</h1>
        <label htmlFor='username'>Username</label>
        <input
          type='text'
          id='username'
          value={username}
          onChange={(e) => setUsername(e.target.value)}
        />
        <label htmlFor='password'>Password</label>
        <input
          type='password'
          id='password'
          value={password}
          onChange={(e) => setPassword(e.target.value)}
        />
        <button onClick={loginUser}>Login</button>
    </div>
  )
}

export default Login
