#include <stdio.h>
int main(){

    // Program to take a number from user and check whether it is perfect number(sum of factors is equal to number itself) or not

    int a;
    printf("Enter a number: ");
    scanf("%d", &a);

    int sum = 0;
    for (int i = 1; i < a; i++){
        if (a%i==0){
            sum += i;
        }
    }

    if (sum==a){
        printf("%d is a perfect number", a);
    }
    else{
        printf("%d is not a perfect number", a);
    }

    return 0;
}