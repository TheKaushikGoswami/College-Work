#include <stdio.h>

// Write a C program to print all odd numbers from 1 to n using for loop.

int main(){

    int n;
    printf("Enter the number upto which you want to print the odd numbers: ");
    scanf("%d", &n);

    for(int i = 1; i<=n; i++){
        if(i%2 != 0){
            printf("%d, ", i);
        }
    }

    return 0;

}