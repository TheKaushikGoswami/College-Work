#include <stdio.h>

int main(){

    float a;

    printf("Enter the temperature (in Celsius): ");
    scanf("%f", &a);

    float f = ((a*9)/5)+32;

    printf("%.2f in Celsius = %.2f in Fahrenheit", a, f);
    return 0;
}