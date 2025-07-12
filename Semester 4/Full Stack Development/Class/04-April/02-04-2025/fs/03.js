const fs = require('fs');

fs.appendFile('Class\\02-04-2025\\test.txt', "Hello, Again", (err) => {
    if (err) throw err;
    console.log("Done!");
})