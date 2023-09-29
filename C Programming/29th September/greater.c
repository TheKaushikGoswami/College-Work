#include <stdio.h>

int main(){

    int a, b;

    printf("Enter 2 integers (seperated by space): ");
    scanf("%d %d", &a, &b);

    /*
    if (a == b){

        printf("Both numbers are equal");

    }

    else{

        if (a>b){

            printf("%d is greater", a);
        }

        else{

            printf("%d is greater", b);
        }

    }

    */

    if (a >= b)
    {

        if (a == b)
        {

            printf("Both numbers are equal");
        }

        else
        {

            printf("%d is greater", a);
        }
    }

    else
    {

        printf("%d is greater", b);
    }

    return 0;
}