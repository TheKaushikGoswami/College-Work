// Use your custom myMap, myFilter, and myReduce implementations to:
// 1.	Filter out numbers greater than 10 from [5, 12, 8, 20, 1].
// 2.	Double the remaining numbers using myMap.
// 3.	Find the sum of the transformed numbers using myReduce.
// Expected Output:
// Sum = 28 (Doubled values of [5, 8, 1] are [10, 16, 2], sum is 28).


function myMap(arr, callback) {
    const result = [];
    for (let i = 0; i < arr.length; i++) {
        result.push(callback(arr[i], i, arr));
    }
    return result;
}

function myFilter(arr, callback) {
    const result = [];
    for (let i = 0; i < arr.length; i++) {
        if (callback(arr[i], i, arr)) {
            result.push(arr[i]);
        }
    }
    return result;
}

function myReduce(arr, callback, initialValue) {
    let accumulator = initialValue !== undefined ? initialValue : arr[0];
    for (let i = initialValue !== undefined ? 0 : 1; i < arr.length; i++) {
        accumulator = callback(accumulator, arr[i], i, arr);
    }
    return accumulator;
}

const numbers = [5, 12, 8, 20, 1];
const filteredNumbers = myFilter(numbers, (num) => num <= 10);
const doubledNumbers = myMap(filteredNumbers, (num) => num * 2);
const sum = myReduce(doubledNumbers, (acc, num) => acc + num, 0);

console.log("Filtered Numbers: ", filteredNumbers); // Output: [5, 8, 1]
console.log("Doubled Numbers: ", doubledNumbers); // Output: [10, 16, 2]
console.log("Sum: ", sum); // Output: 28