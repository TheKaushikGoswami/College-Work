function filterPrimes(arr){
    let filteredArr = arr.filter(num => isPrime(num));
    
    return filteredArr;
}

function isPrime(num){
    if(num <= 1) return false;
    for(let i = 2; i <= num/2; i++){
        if(num % i === 0) return false;
    }
    return true;
}

let arr = [ 10, 20, 50, 60, 80, 100, 30, 2, 3, 5, 7, 11 ];

let filteredArr = filterPrimes(arr);

console.log(filteredArr);