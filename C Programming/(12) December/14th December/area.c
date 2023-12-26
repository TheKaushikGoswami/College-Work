#include <stdio.h>

// C Function that takes circumference of circle as parameter & print it's area

void area(float c){
    float r = c/(2*3.14);
    float ar = 3.14*r*r;

    printf("Area of the circle is %.2f units", ar);
}

int main(){

    float n;
    printf("Enter the circumference of the circle: ");
    scanf("%f", &n);

    area(n);

    return 0;
}
