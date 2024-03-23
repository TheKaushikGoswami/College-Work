#include <stdio.h>
int main(){

    // C Program to print the fibonacci series upto n terms.

    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int a = 0, b = 1, c = 0;
    
    if (n<=0)
        printf("Invalid Input");
    else if (n == 1){
        printf("%d", a);
        return 0;
    }
    else if (n == 2){
        printf("%d\n%d", a, b);
        return 0;
    }
    else{
        
        printf("Fibonacci Series:\n%d\n%d\n", a, b);

        for (int i = 0; i<n-2; i++){
            c = a+b;
            printf("%d\n", c);
            a = b;
            b = c;
        }
    }

    return 0;

}