#include <stdio.h>
int main(){

    // C Program to input any number from the user and check whether the given number is positive, negative, or zero.

    int a;
    printf("Enter a number: ");
    scanf("%d", &a);

    if (a > 0){
        printf("%d is positive.\n", a);
    }
    else if (a < 0){
        printf("%d is negative.\n", a);
    }
    else{
        printf("%d is zero.\n", a);
    }

    return 0;
}