#include<stdio.h>

int factorial(int n){
    int i = 1, fact = 1;
    while(i<=n){
        fact = fact * i;
        i++;
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
    printf("%d", result);
    return 0;
}
