#include <stdio.h>

int main(){

    int a;

    printf("Enter an integer: ");
    scanf("%d", &a);

    if (a>=0){
        
        if (a==0){

            printf("%d", a);
        }

        else{

            printf("%d is Positive.", a);
        }
    }

    else{

        printf("%d is Negative.", a);
    }

    return 0;
}