function main(cb1, cb2, x, y){

    cb1(x, y);
    cb2(x, y);
    
}

function cb1(x, y){
    console.log(x + y);
}

function cb2(x, y){
    console.log(x - y);
}

main(cb1, cb2, 5, 3);