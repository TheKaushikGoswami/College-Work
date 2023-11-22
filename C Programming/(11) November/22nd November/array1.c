#include <stdio.h>
int main(){

    // C Program to take size of array from user and then declare array of that size and then take values of each element from user and then ask user for an element to search & display the index of that element if it exists in the array

    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter the value of element number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int s;
    printf("Enter the element to search: ");
    scanf("%d", &s);

    int index = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == s){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("Element not found in array\n");
    }else{
        printf("Element found at index %d\n", index);
    }

    return 0;
}