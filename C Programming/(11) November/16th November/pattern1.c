#include <stdio.h>

int main(){

    // C Program to print the pattern:
    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4
    // 1 2 3 4 5

    int i, j, n;
    printf("Enter the number of rows: ");

    scanf("%d", &n);

    for(i=1; i<=n; i++){
        for(j=1; j<=i; j++){
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;

}