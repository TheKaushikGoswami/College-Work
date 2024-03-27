#include <stdio.h>

// Write a C program to find sum of all odd numbers from 1 to n using for loop.

int main(){

    int n;
    printf("Enter the number upto which you want to find the sum of odd numbers: ");
    scanf("%d", &n);

    int sum = 0;
    for(int i = 1; i<=n; i++){
        if(i%2 != 0){
            sum += i;
        }
    }

    printf("The sum of all odd numbers from 1 to %d is: %d", n, sum);

    return 0;

}