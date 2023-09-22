#include <stdio.h>

int main(){

    // Divide a number with 64 without using arithmetic operators

    int a;

    printf("Enter an integer: ");
    scanf("%d", &a);

    int b = a>>6;

    printf("%d", b);

    return 0;
}