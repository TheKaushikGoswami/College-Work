#include <stdio.h>

int main(){

    // Reverse the Digits of the Number

    int a;
    printf("Enter a 4 digit number: ");
    scanf("%d", &a);

    int d1 = a/1000;
    a = a%1000;
    int d2 = a/100;
    a = a%100;
    int d3 = a/10;
    int d4 = a%10;

    int r = (d4*1000)+(d3*100)+(d2*10)+d1;

    printf("%d", r);

    return 0;
}