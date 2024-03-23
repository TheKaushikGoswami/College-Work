#include <stdio.h>

int reverse(int num){
    int rev = 0;
    while (num != 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

int main(){

    // C Program to write a function which returns the reverse of any digit number, the number may have any number of digits.

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("The reverse of the number is %d", reverse(num));

    return 0;
}