#include <stdio.h>
int main(){

    // C Program to print the sum of series 1 + (1/2) + (1/3) + (1/4) + (1/5) + ... + (1/n) upto n terms.

    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    float sum = 0;

    for (float i = 1; i<=n; i++){
        sum+=(1/i);
    }

    printf("Sum of the series is: %.2f", sum);

    return 0;
}