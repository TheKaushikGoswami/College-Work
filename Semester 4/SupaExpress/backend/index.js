const express = require('express');
const { PrismaClient } = require('./generated/prisma');
const dotenv = require('dotenv');
const cors = require('cors');

dotenv.config();

const prisma = new PrismaClient();

const app = express();
const port = process.env.PORT || 3000;

app.use(express.json());
app.use(cors());


// Create a new Task
app.post('/tasks', async (req, res) => {
    try{
        const { title } = req.body;
        if(!title) {
            return res.status(400).json({ error: 'Title is required' });
        }

        const task = await prisma.task.create({
            data: { title }
        });
        res.status(201).json(task);
    }
    catch(error){
        console.error(error);
        res.status(500).json({ error: 'An error occurred while creating the task' });
    }
});

// Get all Tasks
app.get('/tasks', async (req, res) => {
    try {
        const tasks = await prisma.task.findMany({
            orderBy: { createdAt: 'desc' }
        });
        res.status(200).json(tasks);
    } catch (error) {
        console.error(error);
        res.status(500).json({ error: 'An error occurred while fetching tasks' });
    }
});

// Get a single Task by ID
app.get('/tasks/:id', async (req, res) => {
    try{
        const { id } = req.params;
        const taskId = parseInt(id, 10);
        if (isNaN(taskId)){
            return res.status(400).json({ error: 'Invalid task ID' });
        }

        const task = await prisma.task.findUnique({
            where: { id: taskId }
        });
        if(!task){
            return res.status(404).json({ error: 'Task not found' });
        }
        res.json(task);
    }
    catch(error){
        console.error(error);
        res.status(500).json({ error: 'An error occurred while fetching the task' });
    }
});

// Update a Task by ID
app.put('/tasks/:id', async (req, res) => {
    try{
        const { id } = req.params;
        const taskId = parseInt(id, 10);
        if (isNaN(taskId)){
            return res.status(400).json({ error: 'Invalid task ID' });
        }

        const { title, completed } = req.body;
        const data = {};
        if (title !== undefined) {
            data.title = title;
        }
        if (completed !== undefined) {
            data.completed = completed;
        }

        const updatedTask = await prisma.task.update({
            where: { id: taskId },
            data
        });
        res.json(updatedTask);
    }
    catch(error){
        console.error(error);
        if (error.code === 'P2025') {
            return res.status(404).json({ error: 'Task not found' });
        }
        res.status(500).json({ error: 'An error occurred while updating the task' });
    }
});

// Delete a Task by ID
app.delete('/tasks/:id', async (req, res) => {
    try{
        const { id } = req.params;
        const taskId = parseInt(id, 10);
        if (isNaN(taskId)){
            return res.status(400).json({ error: 'Invalid task ID' });
        }

        await prisma.task.delete({
            where: { id: taskId }
        });
        res.status(204).send();
    }
    catch(error){
        console.error(error);
        if (error.code === 'P2025') {
            return res.status(404).json({ error: 'Task not found' });
        }
        res.status(500).json({ error: 'An error occurred while deleting the task' });
    }
});

// Graceful shutdown: close Prisma client on exit
process.on('SIGINT', async () => {
    await prisma.$disconnect();
    process.exit();
});

process.on('SIGTERM', async () => {
    await prisma.$disconnect();
    process.exit();
});

// Start the server
app.listen(port, () => {
    console.log(`Server is running on http://localhost:${port}`);
});