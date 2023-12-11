#include <stdio.h>

int is_leap(int n){
    if (n % 4 == 0) {
        if (n % 100 == 0) {
            if (n % 400 == 0) {
                return 1;
            }else{
                return 0;
            }
        }else{
            return 1;
        }
    }else{
        return 0;
    }
}

int main(){

    // C Program to write a function is_leap(int n) to print whether a year is leap year or not.

    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    if (is_leap(year)) {
        printf("The year is a leap year");
    }else{
        printf("The year is not a leap year");
    }

    return 0;
}