#include <stdio.h>

int main(){

    // C Program to make Floyd's Triangle:
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10
    // 11 12 13 14 15

    int i, j, n, k=1;
    printf("Enter the number of rows: ");

    scanf("%d", &n);

    for(i=1; i<=n; i++){
        for(j=1; j<=i; j++){
            printf("%d ", k);
            k++;
        }
        printf("\n");
    }

    return 0;

}