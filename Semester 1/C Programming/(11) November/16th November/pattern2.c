#include <stdio.h>

int main(){

    // C Program to make the pattern:
    // * * * * *
    // * * * *
    // * * *
    // * *
    // *

    int i, j, n;
    printf("Enter the number of rows: ");

    scanf("%d", &n);

    for(i=n; i>=1; i--){
        for(j=1; j<=i; j++){
            printf("* ");
        }
        printf("\n");
    }

    return 0;

}