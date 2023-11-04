#include <stdio.h>

int main(){

    // C Program to print the sum of series 1 + (1/2) + (1/4) + (1/6) + (1/8) + ... + (1/n) upto n terms.

    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    float sum = 1;

    for (float i = 1; i<n; i++){
        sum+=(1/(2*i));
    }

    printf("Sum of the series is: %.2f", sum);

    return 0;

}