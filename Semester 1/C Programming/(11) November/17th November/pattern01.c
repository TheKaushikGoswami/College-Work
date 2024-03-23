#include <stdio.h>

int main(){

    // C program to print a pattern of a given character

    int r, c;
    char ch;
    printf("Enter the number of rows & columns and the character you want to print (separated by space): ");
    scanf("%d %d %c", &r, &c, &ch);

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%c", ch);
        }
        printf("\n");
    }

    return 0;

}