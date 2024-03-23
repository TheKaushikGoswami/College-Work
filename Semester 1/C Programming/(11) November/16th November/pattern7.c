#include <stdio.h>

int main(){

    // C Program to make Pascal's Triangle:
    //       1
    //      1 1
    //     1 2 1
    //    1 3 3 1
    //   1 4 6 4 1
    //  1 5 10 10 5 1
    // 1 6 15 20 15 6 1

    int i, j, n, k=1;
    printf("Enter the number of rows: ");

    scanf("%d", &n);

    for(i=0; i<n; i++){
        for(j=1; j<=n-i; j++){
            printf(" ");
        }
        for(j=0; j<=i; j++){
            if(j==0 || i==0){
                k=1;
            }
            else{
                k = k*(i-j+1)/j;
            }
            printf("%d ", k);
        }
        printf("\n");
    }

    return 0;

}