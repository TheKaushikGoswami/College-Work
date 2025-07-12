let express = require('express');

let app = express();

// app.get('/', (req, res) => {
//     res.send('Hello World');
// });

// app.get('/students/:id', (req, res) => {
//     res.send(`Student ID: ${req.params.id}`);
// });

// // Create a new student using get API, Pass just name and age as parameter and push to the studentsData array

// let studentsData = [];

// app.get('/create/:name/:age', (req, res) => {
//     studentsData.push({ name: req.params.name, age: req.params.age, id: studentsData.length + 1 });
//     res.json(studentsData);
// });



// 21/02/2025

let mongoose = require('mongoose');
let Student = require('./schema/Student');
app.use(express.json());
let dotenv = require('dotenv').config();

mongoose.connect(process.env.MONGODB_URI).then(() => {
    console.log('Connected to MongoDB');
}).catch((err) => {
    console.log('Error: ', err);
});

let student1 = new Student({
    rollNo: 1,
    name: 'Kaushik',
    age: 19,
    city: 'Kolkata'
});

let student2 = new Student({
    rollNo: 2,
    name: 'Prince Raj',
    age: 22,
    city: 'Patna'
});

// student1.save().then(() => {
//     console.log('Student 1 saved');
// }).catch((err) => {
//     console.log('Error: ', err);
// });

// student2.save().then(() => {
//     console.log('Student 2 saved');
// }).catch((err) => {
//     console.log('Error: ', err);
// });

app.post('/create', (req, res) => {
    
    let student = new Student(req.body);

    student.save().then(() => {
        res.json({
            status: "success",
            message: "Student saved",
            data: student
        });
    }).catch((err) => {
        res.json({ 
            status: "error",
            message: err
        });
    });
});

app.get('/students', (req, res) => {
    Student.find().then((students) => {
        res.json({
            status: "success",
            message: "Students found",
            data: students
        });
    }).catch((err) => {
        res.json({
            status: "error",
            message: err
        });
    });
});

app.listen(3000, () => {
    console.log('Server is running on port 3000');
});