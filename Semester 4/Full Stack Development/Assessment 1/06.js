// Write a custom implementation of myMap. Your function myMap(arr, callback) should behave like the native Array.prototype.map method. It should:
// 1.	Take an array and a callback function as arguments.
// 2.	Return a new array with each element transformed by the callback.


function myMap(arr, callback) {
    let result = [];
    for (let i = 0; i < arr.length; i++) {
        result.push(callback(arr[i]));
    }
    return result;
}

const arr = [1, 2, 3, 4];
const doubled = myMap(arr, (num) => num * 2);
console.log(doubled);