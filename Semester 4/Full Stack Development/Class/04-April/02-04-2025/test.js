function myForEach(arr, callback){
    for (let i=0; i<arr.length; i++)
    {
        callback(arr[i], i);
    }
}

const arr1 =[1,2,3,4];
myForEach(arr1, (n, i) => {
    console.log(`Index: ${i}, Value: ${n}`);
})

function myReduce(arr, callback, iV){
    let r = iV;
    for(let i =0; i<arr.length; i++){
        r = callback(r, arr[i]);
    }
    return r;
}

const arr2 = [1,2,3,4];
const sum = myReduce(arr2, (a, b) => a+b, 0);
console.log(sum);

function myFilter(arr, callback){
    const r = [];
    for(let i=0; i<arr.length; i++){
        if(callback(arr[i])){
            r.push(arr[i]);
        }
    }
    return r;
}

const arr3 = [1,2,3,4,5,6,7,8,9,10];
const even = myFilter(arr3, (n) => n%2 === 0);
console.log(even);

function myMap(arr, callback){
    const r =[];
    for(let i=0; i<arr.length; i++){
        r.push(callback(arr[i]));
    }
    return r;
}

const arr4 = [1,2,3,4,5,6,7,8,9,10];
const square = myMap(arr4, (n) => n*n);
console.log(square);