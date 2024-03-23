#include <stdio.h>
#include <math.h>

int main(){

    float principal, rate, time;

    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the rate of interest (in percentage): ");
    scanf("%f", &rate);
    printf("Enter the time (in years): ");
    scanf("%f", &time);

    float si = (principal*rate*time)/100;

    float ci = principal* (pow((1 + rate / 100), time)) - principal;

    printf("Simple Interest: %.2f", si);   
    printf("\nCompound Interest: %.2f", ci); 

    return 0;
    
}