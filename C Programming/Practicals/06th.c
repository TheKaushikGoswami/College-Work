#include <stdio.h>
int main(){

    // C Program to check given number is palindrome or not.

    int num, rev = 0, temp;
    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while(temp > 0){
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }

    if(rev == num){
        printf("%d is a palindrome number.\n", num);
    }
    else{
        printf("%d is not a palindrome number.\n", num);
    }

    return 0;
}