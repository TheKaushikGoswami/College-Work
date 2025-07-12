function myReduce(arr, callback, initialValue){
    let accumulator = initialValue !== undefined ? initialValue : arr[0];
    for (let i = initialValue !== undefined ? 0 : 1; i < arr.length; i++) {
        accumulator = callback(accumulator, arr[i], i, arr);
    }
    return accumulator;
}

const arr = [1, 2, 3, 4];
const sum = myReduce(arr, (acc, num) => acc + num, 0);
console.log(sum); // Output: 10