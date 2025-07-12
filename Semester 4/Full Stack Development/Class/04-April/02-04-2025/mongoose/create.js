const mongoose = require("mongoose");
const express = require("express");
const app = express();

const Uuser = mongoose.Schema({
    name: String,
    email: String,
    password: String
});

const User = mongoose.model("Uuser", Uuser);

mongoose.connect("mongodb+srv://admin:kaushik@internship.v4fbnzf.mongodb.net/?retryWrites=true&w=majority&appName=internship")
.then( async () => {
    console.log("Connected to MongoDB");
    app.listen(5000, () => {
        console.log("Server is running on port 5000");
    });

    await User.insertMany([{
        name : "Kaushik 1",
        email : "thekaushikgoswami@gmail.com",
        password : "password"
    },
    {
        name : "Kaushik 2",
        email : "test2@h.com",
        password : "gybkj"
    },
    {
        name : "Kaushik 3",
        email : "test3@g.com",
        password : "hugyjchg"
    }
]);
})
.catch(error => {
    console.error("Error connecting to MongoDB:", error);
})