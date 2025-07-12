const fs = require('fs');

fs.unlink('Class\\02-04-2025\\test.txt', (err) => {
    if (err) throw err;
    console.log("Deleted!");
})