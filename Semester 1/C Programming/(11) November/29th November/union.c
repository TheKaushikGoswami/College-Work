#include <stdio.h>

int main(){

    // C Program to take 2 arrays from user and create union of those 2 arrays

    int n1, n2, flag;
    printf("Enter the size of array 1: ");
    scanf("%d", &n1);

    int arr1[n1];
    printf("Enter the elements of array 1: ");
    for(int i = 0; i<n1; i++){
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of array 2: ");
    scanf("%d", &n2);

    int arr2[n2];
    printf("Enter the elements of array 2: ");
    for(int i = 0; i<n2; i++){
        scanf("%d", &arr2[i]);
    }

    int arr3[n1+n2];

    for(int i = 0; i<n1; i++){
        arr3[i] = arr1[i];
    }

    int k =  n1;
    for(int i = 0; i<n2; i++){
        flag = 0;
        for(int j = 0; j<n1; j++){
            if(arr2[i] == arr1[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            arr3[k] = arr2[i];
            k++;
        }
    }

    printf("The union of the 2 arrays is: ");
    for(int i = 0; i<k; i++){
        printf("%d ", arr3[i]);
    }

    return 0;
}