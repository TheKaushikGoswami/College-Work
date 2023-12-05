#include <stdio.h>

int main(){

    // C Program to take an array from user and then take an index number from user and delete the element present at that index number

    int n, in;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the index of element to delete: ");
    scanf("%d", &in);

    

}