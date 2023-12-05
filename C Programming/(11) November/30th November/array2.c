#include <stdio.h>

int main(){

    // C Program to take an array from user and then take an element from user and then delete that element from the given array

    int n, a;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to delete: ");
    scanf("%d", &a);

    for(int i=0; i<n; i++){
        if(arr[i] == a){
            for(int j=i; j<n; j++){
                arr[j] = arr[j+1];
                printf("%d ", arr[j]);
            }
            i--;
        }
    }

    printf("The final array is: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;

}
