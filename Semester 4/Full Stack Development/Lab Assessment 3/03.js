const arr = [15, 12, 7, 10, 6, 5, 3, 8, 20, 4];

let evenArr = arr.filter(num => num%2 == 0);

let sum = evenArr.reduce((acc, n) => acc+n, 0);

console.log(evenArr);
console.log(sum);