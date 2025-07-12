// Implement a custom version of the reduce function, myReduce, which takes an array and a callback function as arguments. Ensure it behaves similarly to the native reduce function. Demonstrate it with an example to sum an array of numbers [5, 10, 15, 20].

function myReduce(arr, callback) {
    let acc = arr[0];
    for (let i = 1; i < arr.length; i++) {
        acc = callback(acc, arr[i]);
    }
    return acc;
}

let arr = [5, 10, 15, 20];
let sum = myReduce(arr, (acc, num) => acc + num);
console.log(sum);