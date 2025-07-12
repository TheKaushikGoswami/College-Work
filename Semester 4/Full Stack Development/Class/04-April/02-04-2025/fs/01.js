const fs = require('fs');

fs.readFile('Class\\02-04-2025\\test.txt', (err, data) => {
    if (err) throw err;
    console.log(data.toString());
})

console.log("I am Kaushik")