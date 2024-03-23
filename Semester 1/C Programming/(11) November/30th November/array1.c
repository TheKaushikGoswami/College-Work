#include <stdio.h>

int main(){

    // C Program to take an array from user but declare array of 1 size greater than the given size, after that take an element to insert with it's index number and then insert that element in the given array at the given index number

    int n, in, a;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n+1];
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to insert: ");
    scanf("%d", &a);

    printf("Enter the index number for element: ");
    scanf("%d", &in);

    for(int i=n; i>=in; i--){
        arr[i] = arr[i-1];
    }

    arr[in] = a;

    printf("The final array is: ");
    for(int i=0; i<n+1; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}