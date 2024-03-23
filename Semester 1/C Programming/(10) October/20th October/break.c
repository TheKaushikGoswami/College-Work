#include <stdio.h>
int main(){

    // Program for printing numbers from 1 to n but stop at 10 using break statement

    int n, a = 1;
    printf("Enter a number: ");
    scanf("%d", &n);

    while (a<=n){
        if (a==10){
            break;
        }
        printf("%d\n", a);
        a++;
    }

    return 0;
}