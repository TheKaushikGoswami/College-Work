#include <stdio.h>

int main()
{

    // Write a program to count the number of digits in a number using do-while loop

    int a, c = 0;

    printf("Enter a number: ");
    scanf("%d", &a);

    do
    {
        c++;
        a /= 10;
    }

    while (a != 0);

    printf("The number of digits is: %d", c);

    return 0;
}