const express = require('express');
const mongoose = require('mongoose');
const Uuser = require('./models/User');
const app = express();

mongoose.connect("mongodb+srv://admin:kaushik@internship.v4fbnzf.mongodb.net/?retryWrites=true&w=majority&appName=internship");

app.use(express.json());

app.post("/users", async (req, res) => {
    try{
        const user = new Uuser(req.body);
        await user.save();
        res.status(201).send(user);
    }
    catch(error){
        console.error(error);
        res.status(400).send("Error creating user");
    }
});

app.get('/users/search', async (req, res) => {
    try{
        const user = await Uuser.find({ name: req.body.name });
        if (user.length === 0) {
            return res.status(404).send("User not found");
        }
        res.send(user);
    }
    catch(error){
        console.error(error);
        res.status(500).send("Error retrieving users");
    }
});

app.get("/users/:id", async (req, res) => {
    try{
        const user = await Uuser.findById(req.params.id);
        if (!user) {
            return res.status(404).send("User not found");
        }
        res.send(user);
    }
    catch(error){
        console.error(error);
    }
});

app.put("/users/:id", async (req, res) => {
    try{
        let user = await Uuser.findByIdAndUpdate(req.params.id, req.body);
        if (!user) {
            return res.status(404).send("User not found");
        }
        user = await Uuser.findById(req.params.id);
        res.send(user);
    }
    catch(error){
        console.error(error);
        res.status(400).send("Error updating user");
    }
});

app.delete("/users/:id", async (req, res) => {
    try{
        const user = await Uuser.findByIdAndDelete(req.params.id);
        if (!user) {
            return res.status(404).send("User not found");
        }
        res.send("User deleted successfully");
    }
    catch(error){
        console.error(error);
        res.status(400).send("Error deleting user");
    }
});

app.listen(5000, () => console.log("Server started on port 5000"));