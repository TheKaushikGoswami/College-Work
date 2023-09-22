#include <stdio.h>

int main(){
    
    float a, b, c, d, e;
    scanf("%f\n%f\n%f\n%f\n%f", &a, &b, &c, &d, &e);
    float x = (a+b+c+d+e)/5;
    printf("Percentage Obtained:%.2f%%", x);
    
    return 0;
    
}