#include <stdio.h>
int main(){
    

    /* Logical Operators */

    // && (AND)

    printf("%d", (5>2) && (3>1)); // Both conditions are True, so it will print 1.

    printf("\n%d", (5>2) && (3<1)); // Both conditions are not True, so it will print 0.

    // || (OR)

    printf("\n%d", (20>10) || (20==30)); // Both conditions are not False, so it will print 1.

    printf("\n%d", (20<10) || (22<11)); // Both conditions are False, so it will print 0.

    // ! (NOT)

    printf("\n%d", !(20>10)); // Given condition is True, so it will print 0.

    printf("\n%d", !(20<10)); // Given condition is False, so it will print 1.


    // /* Bitwise Operators */

    // // & (AND Bitwise)

    // printf("\n%d", (5&10)); // The Numbers are not 1, so it will print 0.

    // printf("\n%d", (20&50)); // The Numbers are 1, so it will print 1.

    // int a = 20, b = 50;
    // int c = a | b;
    // printf("\n%d", c);
    
    // int a = 20, b = 50;
    // int c = a ^ b;
    // printf("\n%d", c);

    int a = -4;
    int c = ~a;
    printf("\n%d", c); // negative of (a + 1)

    return 0;

}