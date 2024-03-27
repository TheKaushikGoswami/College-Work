#include <stdio.h>

// Program to find sum of odd numbers in given range from n to m using for loop

int main(){

    int n, m;
    printf("Enter the range of numbers (n to m) upto which you want to find the sum of odd numbers: ");
    scanf("%d %d", &n, &m);

    int sum = 0;
    for(int i = n; i<=m; i++){
        if(i%2 != 0){
            sum += i;
        }
    }

    printf("The sum of all odd numbers from %d to %d is: %d", n, m, sum);

    return 0;
    
}