const fs = require('fs');

async function readFileAsync() {
    await fs.promises.readFile('test.txt', 'utf8')
        .then(
            (data) => {
                console.log(data);
            }
        )
        .catch(
            (err) => {
                console.error('Error reading file:', err);
            }
        )
}

readFileAsync();