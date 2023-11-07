#include <stdio.h>
int main(){

    // C Program to take a number from user and check if it is Armstrong number or not.

    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    int temp = n;
    int sum = 0;

    while (temp>0){
        int rem = temp%10;
        sum += rem*rem*rem;
        temp /= 10;
    }

    if (sum==n)
        printf("%d is an Armstrong number", n);
    else
        printf("%d is not an Armstrong number", n);

    return 0;
}