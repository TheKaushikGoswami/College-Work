#include <stdio.h>

int main(){

    // Write a program to reverse the digits of a number

    int a, b = 0;
    printf("Enter a number: ");
    scanf("%d", &a);

    while(a != 0){
        b = b * 10 + a % 10;
        a /= 10;
    }

    printf("%d", b);

    return 0;
}