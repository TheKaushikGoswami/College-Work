#include <stdio.h>

int main(){

    // C Program to make the pattern:
    //     *    
    //    * *
    //   * * *
    //  * * * *
    // * * * * *

    int i, j, n;
    printf("Enter the number of rows: ");

    scanf("%d", &n);

    for(i=1; i<=n; i++){
        for(j=1; j<=n-i; j++){
            printf(" ");
        }
        for(j=1; j<=i; j++){
            printf("* ");
        }
        printf("\n");
    }

    return 0;

}