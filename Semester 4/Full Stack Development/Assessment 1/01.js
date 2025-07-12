// Write a program in JavaScript to:
// 1.	Filter out all numbers greater than 50 from an array [10, 20, 50, 60, 80, 100, 30, 45].
// 2.	Double all the numbers in the array using map.
// 3.	Find the sum of all numbers in the array using reduce.

let arr = [10, 20, 50, 60, 80, 100, 30, 45];
let filteredArr = arr.filter((num) => num <= 50);
let doubledArr = arr.map((num) => num * 2);
let sum = arr.reduce((acc, num) => acc + num, 0);

console.log(filteredArr);
console.log(doubledArr);
console.log(sum);
