#include <stdio.h>

int main(){

    // Check for Even or Odd

    int a;
    printf("Enter an integer: ");
    scanf("%d", &a);

    if (a%2==0){

        printf("%d is Even", a);
    }
    else{

        printf("%d is Odd", a);
    }

    return 0;
}