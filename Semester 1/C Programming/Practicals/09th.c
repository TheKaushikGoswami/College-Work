#include <stdio.h>
int main(){

    // C Program to print all factors of a number.

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factors of %d are: ", num);

    for(int i = 1; i <= num; i++){
        if(num % i == 0){
            printf("%d ", i);
        }
    }

    return 0;
}