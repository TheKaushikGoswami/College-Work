#include <stdio.h>

// Write a recursive function power that accepts two integers representing a base and an exponent, and returns the base raised to that exponent. For example, the call to power (3, 4) should return 3^4 i.e 81. If the exponent passed is negative, then return -1

int power(int base, int exponent){
    if(exponent < 0){
        return -1;
    }
    if(exponent == 0){
        return 1;
    }
    return base * power(base, exponent-1);
}

int main(){

    int base, exponent;
    printf("Enter the base and exponent: ");
    scanf("%d %d", &base, &exponent);

    int result = power(base, exponent);
    if(result == -1){
        printf("Exponent cannot be negative\n");
    }else{
        printf("%d raised to the power %d is: %d\n", base, exponent, result);
    }

    return 0;

}