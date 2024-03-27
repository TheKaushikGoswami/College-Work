#include <stdio.h>

// Write a recursive function gcd that accepts two positive non zero integer parameters I and j and return the greatest common divisor of these numbers.

int gcd(int i, int j){
    if(j == 0){
        return i;
    }
    else if(i == 0){
        return j;
    }
    return gcd(j, i%j);
}

int main(){

    int i, j;
    printf("Enter two numbers: ");
    scanf("%d %d", &i, &j);

    int result = gcd(i, j);
    printf("GCD of %d and %d is: %d\n", i, j, result);

    return 0;

}