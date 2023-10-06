#include <stdio.h>

int main(){

    int a, b, c;

    printf("Enter the three numbers (separated by space): ");
    scanf("%d %d %d", &a, &b, &c);

    if (a > b && a > c){
        printf("%d is the greatest number", a);
    }
    else if (b > a && b > c){
        printf("%d is the greatest number", b);
    }
    else if (c > a && c > b){
        printf("%d is the greatest number", c);
    }
    else if (c == a && c == b){
        printf("All are equal");
    }

    else if (c == a){
        printf("%d is the greatest number", a);
    }
    else if (c == b){
        printf("%d is the greatest number", b);
    }
    else if (a == b){
        printf("%d is the greatest number", a);
    }

    return 0;
}