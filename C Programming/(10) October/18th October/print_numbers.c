#include <stdio.h>

int main()
{

    // Write a program to print 'n' natural numbers using while loop

    int a;
    int b = 1;

    printf("Enter a number: ");
    scanf("%d", &a);

    do {
        printf("%d\n", b);
        b++;
    }
    
    while (b <= a);

    return 0;
}