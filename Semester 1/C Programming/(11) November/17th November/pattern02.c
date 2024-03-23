#include <stdio.h>

int main(){

    // C program to print the following pattern:
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 1
    // 2 3 4 5 6
    // 7 8 9 1 2 3

    int r, c, n = 1;
    printf("Enter the number of rows: ");
    scanf("%d", &r);

    for(int i = 0; i < r; i++){
        for(int j = 0; j <= i; j++){
            printf("%d ", n);
            n++;
            if(n == 10){
                n = 1;
            }
        }
        printf("\n");
    }

    return 0;

}