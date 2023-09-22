#include <stdio.h>

int main() {

    // Greatest of 2 Integers without using if-else

    int a, b;
    printf("Enter 1st integer: ");
    scanf("%d", &a);
    printf("Enter 2nd integer: ");
    scanf("%d", &b);

    int c = ((a>=b)*a) + ((b>a)*b);

    printf("%d", c);

    return 0;

}