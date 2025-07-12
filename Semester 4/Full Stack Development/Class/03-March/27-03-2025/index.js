const fs = require('fs');
const mongoose = require('mongoose');
const express = require('express');
const app = express();
const dotenv = require('dotenv');
dotenv.config();

app.use(express.json());

mongoose.connect(process.env.MONGODB_URI).then(() => {
    console.log('Connected to MongoDB');
    
    fs.readFile('chitkaras.csv', 'utf8', (err, data) => {
        if (err) {
            console.error(err);
            return;
        }
        // Get all the rows one by one
        const rows = data.split('\n');
        // Split using comma
        const headers = rows[0].split(';');
    
        // Create a schema using the first row
        const dataSchema = new mongoose.Schema({});
    
        headers.forEach((header) => {
            dataSchema.add({
                [header]: String
            });
        });
    
        // Create a model
        const Data = mongoose.model('Data', dataSchema);
    
        // Insert data into the model
        for (let i = 1; i < rows.length; i++) {
            const row = rows[i].split(';');
            const data = new Data({});
            headers.forEach((header, index) => {
                data[header] = row[index];
            });
            data.save();
        }
    
        // On successful insertion
        console.log('Data inserted successfully');
    });
}).catch((err) => {
    console.log('Error: ', err);
});