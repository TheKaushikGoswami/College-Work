#include <stdio.h>

int main(){

    int a, b;
    a = 10;
    b = 3;

    float c;
    c = (float)a/b;

    printf("%.2f", c);

    printf("\n%f", a/(float)b);

    /*

    int/int = int
    int/float = float
    float/int = float
    float/float = float

    */

    return 0;
}