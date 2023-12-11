#include <stdio.h>

float area(float radius){
        return 3.14 * radius * radius;
}

int main(){

    // C Program to make a function which takes radius of circle as argument and returns the area of circle.

    float radius;
    printf("Enter radius of circle: ");
    scanf("%f", &radius);

    printf("The area of circle is %.2f", area(radius));

    return 0;

}