#include <stdio.h>

// Write a C program to print all prime numbers between 1 to n.

int isPrime(int n){
    if(n == 1){
        return 0;
    }
    for(int i = 2; i<=n/2; i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){

    int n;
    printf("Enter the number upto which you want to print the prime numbers: ");
    scanf("%d", &n);

    for(int i = 1; i<=n; i++){
        if(isPrime(i)){
            printf("%d, ", i);
        }
    }

    return 0;

}