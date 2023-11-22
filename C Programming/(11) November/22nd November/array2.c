#include <stdio.h>
int main(){

    // C Program to take size of array from user and then declare array of that size and then take values of each element from user and then print the maximum and minimum element of the array

    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter the value of element number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int min = arr[0];

    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }

    // For finding 2nd largest

    int max2 = min;

    for(int i = 0; i < n; i++){
        if(arr[i] > max2 && arr[i] < max){
            max2 = arr[i];
        }
    }

    printf("2nd largest element is %d\n", max2);
    
    printf("Maximum element is %d\n", max);
    printf("Minimum element is %d\n", min);

    return 0;
}