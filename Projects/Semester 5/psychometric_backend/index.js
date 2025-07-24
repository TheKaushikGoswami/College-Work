const express = require('express');
const cors = require('cors');
const mysql = require('mysql');

const app = express();
app.use(cors());
app.use(express.json());

const db = mysql.createConnection({
    host: '139.162.29.31',
    user: 'kashishj_psychometric_admin',
    password: 'Admin@2025',
    database: 'kashishj_psychometric'
});

db.connect((err) => {
    if (err) {
        console.error('Database connection failed:', err.stack);
        return;
    }
    console.log('Connected to MySQL database.');
});

app.get('/', (req, res) => {
    const sql = `SELECT * FROM test_details`;

    db.query(sql, (error, results) => {
        if (error) {
            console.error('Error fetching data:', error);
            return res.status(500).send('Error fetching data');
        }
        res.json(results);
    });
});

app.post('/submit-details', (req, res) => {
    const {
        name,
        dob,
        course,
        married,
        education,
        religion,
        gender,
        email,
        phone,
        occupation,
        institution,
        rural_or_urban,
        test_name,
        score,
        result
    } = req.body;

    const newRecord = {
        name: name,
        dob: dob,
        course: course,
        married: married ? 1 : 0,
        education: education,
        religion: religion,
        gender: gender,
        email: email,
        phone: phone,
        occupation: occupation,
        institution: institution,
        rural_or_urban: rural_or_urban,
        test_name: test_name,
        score: score,
        result: result
    };

    const sql = `
        INSERT INTO test_details 
        (name, dob, course, married, education, religion, gender, email, phone, occupation, institution, rural_or_urban, test_name, score, result, timestamp) 
        VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, NOW())
    `;

    db.query(sql, Object.values(newRecord), (error, results) => {
        if (error) {
            console.error('Error inserting data:', error);
            return res.status(500).send('Error inserting data');
        }
        res.status(201).send('Details submitted successfully');
    });
});

app.listen(3000, () => {
    console.log('Server started on port 3000');
});