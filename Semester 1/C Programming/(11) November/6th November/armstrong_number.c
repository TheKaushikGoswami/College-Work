#include <stdio.h>
#include <math.h>

int main() {

    // C Program to take a number from user and check if it is Armstrong number or not.
    // Armstrong Number is a number which is equal to the sum of digits raise to the power total number of digits in the number.
    // For Example, 9474. As, 9^4 + 4^4 + 7^4 + 4^4 = 9474

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

