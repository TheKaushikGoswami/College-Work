#include <stdio.h>

int main(){

    // C program to print the following pattern:
    // A
    // B C
    // D E F
    // G H I J

    int r, c, n = 65;
    printf("Enter the number of rows: ");
    scanf("%d", &r);

    for(int i = 0; i < r; i++){
        for(int j = 0; j <= i; j++){
            printf("%c ", n);
            n++;

            if (n == 91){
                n = 65;
            }
        }
        printf("\n");
    }

    return 0;

}