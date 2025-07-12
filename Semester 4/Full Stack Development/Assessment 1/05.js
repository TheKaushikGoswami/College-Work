// Write a function manipulateArray(arr, operations) that takes an array and a list of operations. Each operation will be a string "filter", "map", or "reduce".
// ●	"filter" should filter out numbers less than 10.
// ●	"map" should multiply each element by 2.
// ●	"reduce" should sum all elements.
// Demonstrate your function with [3, 15, 20, 8, 5, 12] and the operation sequence ["filter", "map", "reduce"].

function manipulateArray(arr, operations) {
    let result = arr;
    for (let i = 0; i < operations.length; i++) {
        if (operations[i] === "filter") {
        result = result.filter((element) => element >= 10);
        } else if (operations[i] === "map") {
        result = result.map((element) => element * 2);
        } else if (operations[i] === "reduce") {
        result = result.reduce((acc, element) => acc + element);
        }
    }
    return result;
}
    
console.log(manipulateArray([3, 15, 20, 8, 5, 12], ["filter", "map", "reduce"]));