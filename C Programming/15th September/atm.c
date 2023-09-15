#include <stdio.h>

int main(){

    // Take input of amount and display the denomination of 2000, 500 & 100 Rupees notes
    
    int amount, a, b, c;

    printf("Enter the amount: ");
    scanf("%d", &amount);

    a = amount/2000;
    int x = amount%2000;
    b = x/500;
    int y = amount%500;
    c = y/100;
    
    printf("2000 Rs Notes: %d\n", a);
    printf("500 Rs. Notes: %d\n", b);
    printf("100 Rs. Notes: %d", c);

    return 0;

}