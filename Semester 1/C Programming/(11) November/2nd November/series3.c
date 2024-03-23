#include <stdio.h>

int main(){

    // C Program to print the sum of series 1 + (1/2) + (2/3) + (3/4) + (5/6) + ... + (n-1)/n upto n terms.

    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    float sum = 1;

    for (float i = 1; i<n; i++){
        sum+=((i)/(i+1));
    }

    printf("Sum of the series is: %.2f", sum);

    return 0;

}