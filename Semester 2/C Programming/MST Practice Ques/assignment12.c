#include <stdio.h>

// Write a program in C to convert a binary number to a decimal number using the function.

int binaryToDecimal(int n){
    if(n == 0){
        return 0;
    }
    else{
        return (n%10 + 2*binaryToDecimal(n/10));
    }
}

int main(){
    int n;
    printf("Enter a binary number: ");
    scanf("%d", &n);
    
    int decimal = binaryToDecimal(n);
    printf("The decimal value is: %d", decimal);
    
    return 0;
}