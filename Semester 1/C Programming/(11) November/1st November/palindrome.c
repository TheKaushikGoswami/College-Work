#include <stdio.h>
int main(){

    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    int n = a;
    int x = 0;

    while(a!=0){

        x = (x*10) + (a%10);
        a/=10;

    }

    if (n<10){
        printf("%d is Palindrome.", n);
    }

    else if (x == n){
        printf("%d is Palindrome.", n);
    }

    else{
        printf("%d is not a Palindrome.", n);
    }

    return 0;

}