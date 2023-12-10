#include <stdio.h>
int main(){

    // C Program to print different pattern with input from the user:

    /*

    Pattern 1:

    *
    **
    ***
    ****
    *****
    
    Pattern 2:

         *
        ***
       *****
      *******
     *********
    
    Pattern 3:

        *
       **
      ***
     ****
    *****
    
    */

    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    printf("\nPattern 1:\n\n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }

    printf("\nPattern 2:\n\n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n - i; j++){
            printf(" ");
        }
        for(int j = 1; j <= 2 * i - 1; j++){
            printf("*");
        }
        printf("\n");
    }

    printf("\nPattern 3:\n\n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n - i; j++){
            printf(" ");
        }
        for(int j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}