#include <stdio.h>
int main(){

    // C Program to take 2 numbers from user and find their LCM.

    int n1, n2;
    printf("Enter both numbers (separated by space): ");
    scanf("%d %d", &n1, &n2);

    int i;
    for (i = n1; i<=n1*n2; i++){
        if (i%n1==0 && i%n2==0){
            printf("The LCM of %d and %d is %d", n1, n2, i);
            break;
        }
    }

    return 0;
}