#include <stdio.h>

// Write a C program to print The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21 
int main(){

    int n;
    printf("Enter the number of terms you want to print: ");
    scanf("%d", &n);

    int a = 0, b = 1, c;
    printf("%d, %d, ", a, b);
    for(int i = 3; i<=n; i++){
        c = a + b;
        printf("%d, ", c);
        a = b;
        b = c;
    }

    return 0;

}