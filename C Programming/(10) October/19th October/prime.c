#include <stdio.h>

int main(){

    // Program for checking if the given number is prime or not

    int a, n = 0;
    printf("Enter a number: ");
    scanf("%d", &a);

    if (a<2){
        n = 1;
    }

    for(int i=2; i<a; i++){
        if(a%i == 0){
            n = 1;
            break;
        }
    }

    if(n == 0){
        printf("%d is a prime number.", a);
    }
    else{
        printf("%d is not a prime number.", a);
    }

    return 0;
}