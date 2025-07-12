// Use your custom myMap, myFilter, and myReduce implementations to:
// 1.	Filter out numbers greater than 10 from [5, 12, 8, 20, 1].
// 2.	Double the remaining numbers using myMap.
// 3.	Find the sum of the transformed numbers using myReduce.


function myFilter(arr, callback) {
    let result = [];
    for (let i = 0; i < arr.length; i++) {
        if (callback(arr[i])) {
            result.push(arr[i]);
        }
    }
    return result;
}

function myMap(arr, callback) {
    let result = [];
    for (let i = 0; i < arr.length; i++) {
        result.push(callback(arr[i]));
    }
    return result;
}

function myReduce(arr, callback, initialValue) {
    let result = initialValue;
    for (let i = 0; i < arr.length; i++) {
        result = callback(result, arr[i]);
    }
    return result;
}

const arr = [5, 12, 8, 20, 1];
const filtered = myFilter(arr, (num) => num <= 10);
const doubled = myMap(filtered, (num) => num * 2);
const sum = myReduce(doubled, (acc, num) => acc + num, 0);
console.log(sum);