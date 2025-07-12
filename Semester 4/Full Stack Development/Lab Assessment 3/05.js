// Write a function manipulateArray(arr, operations) that takes an array and a list of operations. Each operation will be a string "filter", "map", or "reduce".
// ●	"filter" should filter out numbers less than 10.
// ●	"map" should multiply each element by 2.
// ●	"reduce" should sum all elements.
// Demonstrate your function with [3, 15, 20, 8, 5, 12] and the operation sequence ["filter", "map", "reduce"].


function manipulateArray(arr, operations) {
    let result = arr;

    operations.forEach(operation => {
        if (operation === "filter") {
            result = result.filter(num => num < 10);
        } else if (operation === "map") {
            result = result.map(num => num * 2);
        } else if (operation === "reduce") {
            result = result.reduce((acc, num) => acc + num, 0);
        }
    });

    return result;
}

const arr = [3, 15, 20, 8, 5, 12];
const operations = ["filter", "map", "reduce"];

const result = manipulateArray(arr, operations);
console.log(result);