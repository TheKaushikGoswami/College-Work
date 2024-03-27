#include <stdio.h>

// Write a program in C to find the sum of elements of an array using a pointer.

int sum(int *p, int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += *(p+i);
    }
    return sum;
}
int main(){

    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int *ptr = arr;

    int result = sum(ptr, n);

    printf("Sum of elements of array is: %d", result);

    return 0;
}