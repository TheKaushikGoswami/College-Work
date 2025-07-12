const express = require('express');
const app = express();

app.use(express.json());

app.post('/test', (req, res) => {
    console.log(req.body);
    res.json(
        {
            "name" : req.body.name,
            "age" : req.body.age
        }
    )
})

app.listen(5000, () => console.log("Server is running on port 5000"));