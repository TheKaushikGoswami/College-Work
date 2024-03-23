#include <stdio.h>
int main(){

    int n1, n2;
    printf("Enter 2 numbers (separated by space, 1st number should be base and 2nd snumber should be power): ");
    scanf("%d %d", &n1, &n2);

    int x = 1;

    for (int i = n2; i!=0; i--){
        x*=n1;
    }

    printf("%d^%d = %d", n1, n2, x);

    return 0;

}