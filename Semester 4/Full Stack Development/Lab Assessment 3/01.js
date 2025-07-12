let arr = [ 10, 20, 50, 60, 80, 100, 30, 45 ];

let filteredArr = arr.filter(num => num > 50);
console.log(filteredArr);

let doubledArr = arr.map(num => num * 2);
console.log(doubledArr);

let sum = arr.reduce((acc, n) => acc+n, 0);
console.log(sum);