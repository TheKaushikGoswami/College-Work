#include <stdio.h>

int main() {

    // Absolute Value of an Integer without using if-else

    int a;
    printf("Enter an integer: ");
    scanf("%d", &a);

    int c = ((a>0)*a) - ((a<0)*a);

    printf("%d", c);

    return 0;

}