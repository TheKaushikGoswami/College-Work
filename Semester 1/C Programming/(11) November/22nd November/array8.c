#include <stdio.h>
int main(){

    // C Program to take an array from user and remove the repeated elements from the array

    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter the value of element number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("The array before cleaning is: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] == arr[j]){
                for(int k = j; k < n; k++){
                    arr[k] = arr[k+1];
                }
                n--;
                j--;
            }
        }
    }

    printf("\nThe array after cleaning is: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}