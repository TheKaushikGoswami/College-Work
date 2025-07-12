// Write a custom implementation of myReduce. Your function myReduce(arr, callback, initialValue) should behave like the native Array.prototype.reduce method. It should:
// 1.	Take an array, a callback, and an initial value as arguments.
// 2.	Accumulate the result by applying the callback to each element of the array.

function myReduce(arr, callback, initialValue) {
    let result = initialValue;
    for (let i = 0; i < arr.length; i++) {
        result = callback(result, arr[i]);
    }
    return result;
}

const arr = [1, 2, 3, 4];
const sum = myReduce(arr, (acc, num) => acc + num, 0);
console.log(sum);
