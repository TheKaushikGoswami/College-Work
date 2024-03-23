#include <stdio.h>
int main(){

    // C Program to swap the value of two variables without using a third variable

    int a, b;
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);

    printf("Before swapping:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("After swapping:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}