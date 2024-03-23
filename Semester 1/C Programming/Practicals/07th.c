#include <stdio.h>
int main(){

    // C Program to find a GCD(HCF) of two numbers.

    int n1, n2, hcf;
    printf("Enter two numbers (separated by space): ");
    scanf("%d %d", &n1, &n2);
    if (n1 == 0 || n2 == 0){
        printf("%d", n1+n2);
        return 0;
    }
    for(int i = 1; i <= n1 && i <= n2; i++){
        if(n1 % i == 0 && n2 % i == 0){
            hcf = i;
        }
    }

    printf("HCF of %d and %d is %d.\n", n1, n2, hcf);

    return 0;
}
