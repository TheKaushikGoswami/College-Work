const express = require('express');
const app = express();
const cors = require('cors');
// app.use(cors());

function logger(req, res, next) {
    const timestamp = new Date().toISOString();
    console.log(`${timestamp} - ${req.method} ${req.url}`);
    next();
}

app.get('/home', logger, (req, res) => {
    res.json({
        message: 'Welcome to the home page'
    });
});

app.get('/about', (req, res) => {
    res.send('This is the about page');
});

app.get('/contact', logger, (req, res) => {
    res.json({
        message: 'This is the contact page'
    });
});

app.listen(5000, () => {
    console.log('Server running')
})