// Write a function filterPrimes(arr) that takes an array of numbers and uses filter to return only the prime numbers. Use a helper function isPrime(num) to determine if a number is prime.

function filterPrimes(arr) {
    return arr.filter(isPrime);
}

function isPrime(num) {
    if (num < 2) return false;
    for (let i = 2; i < num; i++) {
        if (num % i === 0) return false;
    }
    return true;
}

console.log(filterPrimes([7, 9, 3, 9, 10, 11, 27]));
console.log(filterPrimes([100, 101, 103, 104, 105, 107]));