#include <stdio.h>

int main(){

    // Sum of Digits of the Number

    int a;
    printf("Enter a 3 digit number: ");
    scanf("%d", &a);

    int d1 = a/100;
    a = a%100;
    int d2 = a/10;
    int d3 = a%10;

    printf("%d", d1+d2+d3);

    return 0;

}