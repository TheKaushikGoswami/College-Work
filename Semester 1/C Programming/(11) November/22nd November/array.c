#include <stdio.h>
int main(){

    // C Program to take size of array from user and then declare array of that size and then take values of each element from user and then print the array with space between each element

    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter the value of element number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("The array is: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}