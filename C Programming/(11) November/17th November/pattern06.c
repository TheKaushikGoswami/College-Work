#include <stdio.h>

int main(){

    // C program to print the following pattern:
    // *                 *
    // * *             * *
    // * * *         * * *
    // * * * *     * * * *
    // * * * * * * * * * *

    int r;
    printf("Enter the number of rows: ");
    scanf("%d", &r);

    for(int i = 1; i <= r; i++){

        /*

        for(int j = 1; j <= i; j++){
            printf("* ");
        }
        for(int k = 1; k <= 2 * (r - i); k++){
            printf("  ");
        }
        for(int l = 1; l <= i; l++){
            printf("* ");
        }
        printf("\n");

        */

        for(int j = 1; j<=2*r; j++){
            if(j <= i || j > 2*r - i){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }

        printf("\n");

    }

    return 0;

}