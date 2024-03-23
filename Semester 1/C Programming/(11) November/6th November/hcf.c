#include <stdio.h>
int main(){

    // C Program to take 2 numbers from user and find their Highest Common Factor (HCF).

    int n1, n2;
    printf("Enter both numbers (separated by space): ");
    scanf("%d %d", &n1, &n2);

    int i;
    for (i = n1; i>0; i--){
        if (n1%i==0 && n2%i==0){
            printf("The HCF of %d and %d is %d", n1, n2, i);
            break;
        }
    }

    if (i==0)
        printf("The HCF of %d and %d is 1", n1, n2);

    return 0;

}