#include <stdio.h>
int main(){

    // Program for printing numbers from 1 to n except 10 using continue statement

    int n, a = 1;
    printf("Enter a number: ");
    scanf("%d", &n);

    while (a<=n){
        if (a==10){
            a++;
            continue;
        }
        printf("%d\n", a);
        a++;
    }

    return 0;
}