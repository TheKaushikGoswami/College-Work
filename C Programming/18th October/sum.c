#include <stdio.h>

int main()
{

    // Write a program to print sum of 'n' natural numbers using while loop

    int a;
    int sum = 0;
    printf("Enter a number: ");
    scanf("%d", &a);

    do {
        sum += a;
        a--;
    }
    
    while (a >= 1);

    printf("Sum is %d", sum);

    return 0;
}