#include<stdio.h>

// Write a program in C to find the sum of the series 1!/1 + 2!/2 + 3!/3 + 4!/4 + 5!/5 using the function

int factorial(int n){
    int fact = 1;
    for(int i = 1; i<=n; i++){
        fact *= i;
    }
    
    return fact;
}

int main(){
    int n = 5, i = 1;
    int result = 0;
    while(i<=n){
        result += factorial(i)/i;
        i++;
    }
    printf("The sum of the series is: %d", result);
    return 0;
}
