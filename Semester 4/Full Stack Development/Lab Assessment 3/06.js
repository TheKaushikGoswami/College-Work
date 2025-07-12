// Write a custom implementation of myMap. Your function myMap(arr, callback) should behave like the native Array.prototype.map method. It should:
// 1.	Take an array and a callback function as arguments.
// 2.	Return a new array with each element transformed by the callback.
// Example:
// function myMap(arr, callback) {
// // Your implementation here
// }

// const arr = [1, 2, 3, 4];
// const doubled = myMap(arr, (num) => num * 2); console.log(doubled); // Output: [2, 4, 6, 8]


function myMap(arr, callback) {
    let newArr = [];
    for (let i = 0; i < arr.length; i++) {
        newArr.push(callback(arr[i], i, arr));
    }
    return newArr;
}

const arr = [1, 2, 3, 4];
const doubled = myMap(arr, (num) => num * 2);
console.log(doubled); // Output: [2, 4, 6, 8]