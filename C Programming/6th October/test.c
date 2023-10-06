#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Write a function where the 1st integer is used for comparison & 2nd integer is threshold. Then find the bitwise and, or & xor of both numbers. Print them in decreasing order of their values (separated by new line). If any number is below the threshold, print the threshold value.

void calculate_the_maximum(int n, int k){

    int max1, max2, max3;

    int n_and = (n&k);
    int n_or = (n|k);
    int n_xor = (n^k);

    if (n_and > n_or && n_and > n_xor){
        max1 = n_and;
        max2 = n_or;
        max3 = n_xor;
    }
    else if (n_or > n_and && n_or > n_xor){
        max1 = n_or;
        max2 = n_and;
        max3 = n_xor;
    }
    else if (n_xor > n_and && n_xor > n_or){
        max1 = n_xor;
        max2 = n_and;
        max3 = n_or;
    }
    else{
        max1 = n_and;
        max2 = n_or;
        max3 = n_xor;
    }

    printf("%d\n%d\n%d", max1, max2, max3);
}


int main(){
    
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;

}