#include <stdio.h>

int main(){

    // C program to print the following pattern:
    // A
    // A B
    // A B C
    // A B C D

    int r, c;
    printf("Enter the number of rows: ");
    scanf("%d", &r);

    for(int i = 0; i < r; i++){
        for(int j = 0; j <= i; j++){
            printf("%c ", 65 + j);
        }
        printf("\n");
    }

    return 0;

}