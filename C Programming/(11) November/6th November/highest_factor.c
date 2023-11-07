#include <stdio.h>
int main(){

    // C Program to print only the highest factor of a number using for loop.

    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    int i;
    for (i = 2; i<n; i++){
        if (n%i==0){
            printf("The highest factor of %d is %d", n, n/i);
            break;
        }
    }

    if (i==n)
        printf("The number is prime");

    return 0;

}