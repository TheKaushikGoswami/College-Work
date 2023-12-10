#include <stdio.h>
#include <math.h>
int main(){

    // C Program to input any number from user and check whether the given number is armstrong or not.

    int num, temp, rem, sum = 0, count = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while (temp != 0) {
        count++;
        temp /= 10;
    }

    temp = num;

    while (temp != 0) {
        rem = temp % 10;
        sum += pow(rem, count);
        temp /= 10;
    }

    if (sum == num) {
        printf("%d is an Armstrong number.", num);
    } else {
        printf("%d is not an Armstrong number.", num);
    }
    
    return 0;
}