let mongoose = require('mongoose');

let studentSchema = new mongoose.Schema({
    rollNo: Number,
    name: String,
    age: Number,
    city: String
})

let Student = mongoose.model('Student', studentSchema);

module.exports = Student;