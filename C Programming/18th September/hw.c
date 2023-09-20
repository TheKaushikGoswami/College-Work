#include <stdio.h>

int main(){

    int a, b;

    printf("Enter the 1st integer: ");
    scanf("%d", &a);
    printf("Enter the second integer: ");
    scanf("%d", &b);

    printf("Before swap, a=%d b=%d", a, b);

    a+=b;
    b=a-b;
    a-=b;

    printf("\nAfter swap, a=%d b=%d", a, b);

    return 0;
}