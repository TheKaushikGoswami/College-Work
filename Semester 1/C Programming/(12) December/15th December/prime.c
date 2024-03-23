#include <stdio.h>

// C Program that takes an integer number as argument and return 1 if the number is prime and return 0 if the number is not prime (if the number is 1, return 0)

int isPrime(int x){

    int y = 1;

    if (x<2){
        y = 0;
    }

    else{
        for(int i=2; i<x; i++){
            if(x%i == 0){
                y = 0;
                break;
            }
        }
    }

    return y;

}

int main(){

    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int z = isPrime(n);

    printf("%d", z);

    return 0;

}