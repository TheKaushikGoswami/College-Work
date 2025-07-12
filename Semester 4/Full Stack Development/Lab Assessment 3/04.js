// Implement a custom version of the reduce function, myReduce, which takes an array and a callback function as arguments. Ensure it behaves similarly to the native reduce function.
// Demonstrate it with an example to sum an array of numbers [5, 10, 15, 20].

function myReduce(arr, callback, initialValue) {
    let accumulator = initialValue !== undefined ? initialValue : arr[0];
    for (let i = initialValue !== undefined ? 0 : 1; i < arr.length; i++) {
        accumulator = callback(accumulator, arr[i], i, arr);
    }
    return accumulator;
}

const numbers = [5, 10, 15, 20];
const sum = myReduce(numbers, (acc, num) => acc + num, 0);

console.log(sum);