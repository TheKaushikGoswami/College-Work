// frontend/utils/api.js

import axios from 'axios';

// Point this at your Express backend
const API_BASE = 'http://localhost:3000';

export const api = axios.create({
  baseURL: API_BASE,
  headers: {
    'Content-Type': 'application/json',
  },
});
