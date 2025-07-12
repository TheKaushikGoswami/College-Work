const fs = require('fs');
try{
    const data = fs.readFileSync('Class\\02-04-2025\\test.txt');
    console.log(data.toString());
}
catch(err){
    console.error(err);
}

console.log("I am Kaushik")