#include <stdio.h>

// Write a program in C to convert a decimal number to a binary number using the function.
int decimalToBinary(int n){
    if(n == 0){
        return 0;
    }
    else{
        return (n%2 + 10*decimalToBinary(n/2));
    }
}

int main(){
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    
    int binary = decimalToBinary(n);
    printf("The binary value is: %d", binary);
    
    return 0;
}