#include <stdio.h>

int main(){

    // C program to print the following pattern:
    //       *
    //     * * *
    //   * * * * *
    // * * * * * * *


    int r, c;
    printf("Enter the number of rows: ");
    scanf("%d", &r);

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= r - i; j++){
            printf("  ");
        }
        for(int k = 1; k <= 2 * i - 1; k++){
            printf("* ");
        }
        printf("\n");
    }

    return 0;

}