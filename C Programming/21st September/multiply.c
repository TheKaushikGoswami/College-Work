#include <stdio.h>

int main(){

    // Multiply a number with 33 without using arithmetic operators

    int a;

    printf("Enter an integer: ");
    scanf("%d", &a);

    int b = (a<<5)+a;

    printf("%d", b);

    return 0;

}