const fs = require('fs');

fs.writeFile('Class\\02-04-2025\\test.txt', "Hello, Again", (err) => {
    if (err) throw err;
    console.log("Done!");
})