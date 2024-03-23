#include <stdio.h>
#include <math.h>
int main(){

    // Consider the series below x+x^2/4+x^3/9+x^4/16 
    // Input the value of x and no of terms from users and calculate the sum of series upto terms specified e.g X=3 & terms=2 the series would be 3+9/4.

    int x, terms;
    float sum = 0;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    for(int i = 1; i <= terms; i++){
        sum += (float)pow(x, i) / (float)pow(i, 2);
    }

    printf("The sum of the series is %f", sum);

    return 0;
}