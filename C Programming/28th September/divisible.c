#include <stdio.h>

int main(){

    // Nested if-else application

    int a;
    printf("Enter an integer: ");
    scanf("%d", &a);

    if (a%3 == 0){

        if (a%7 == 0){
            printf("The number is divisible by both 3 and 7");
        }
        else{
            printf("The number is divisible by 3 only");
        }
    }

    else{

        if (a%7 == 0){
            printf("The number is divisible by 7 only");
        }
        else{
            printf("The number is not divisible by either 3 or 7");
        }
    }

    return 0;
}