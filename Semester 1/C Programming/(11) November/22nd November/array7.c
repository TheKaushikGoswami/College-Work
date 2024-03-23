#include <stdio.h>
int main(){

    // C Program to take two arrays from user and find the intersection of those arrays

    int n1;
    printf("Enter the size of array 1: ");
    scanf("%d", &n1);

    int arr1[n1];

    for(int i = 0; i < n1; i++){
        printf("Enter the value of element number %d of array 1: ", i+1);
        scanf("%d", &arr1[i]);
    }

    int n2;
    printf("Enter the size of array 2: ");
    scanf("%d", &n2);

    int arr2[n2];

    for(int i = 0; i < n2; i++){
        printf("Enter the value of element number %d of array 2: ", i+1);
        scanf("%d", &arr2[i]);
    }

    int arr3[n1+n2];

    int k = 0;

    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(arr1[i] == arr2[j]){
                arr3[k] = arr1[i];
                k++;
            }
        }
    }

    printf("The intersection of the two arrays is: ");

    for(int i = 0; i < k; i++){
        printf("%d ", arr3[i]);
    }

    return 0;
}