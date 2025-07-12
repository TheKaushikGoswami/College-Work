// Given an array of integers [15, 12, 7, 10, 6, 5, 3, 8, 20, 4], write a program to:
// 1.	Use filter to extract even numbers.
// 2.	Calculate the average of those even numbers using reduce.


function filterEven(arr) {
    return arr.filter(num => num % 2 === 0);
}

function average(arr) {
    return arr.reduce((acc, num) => acc + num) / arr.length;
}

let arr = [15, 12, 7, 10, 6, 5, 3, 8, 20, 4];
let evens = filterEven(arr);
console.log(evens);

let avg = average(evens);
console.log(avg);