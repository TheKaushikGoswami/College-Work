#include <stdio.h>
int main(){

    // C Program to take an array from user and create 2 arrays with even and odd elements in each array from the given array

    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter the value of element number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int even[n], odd[n];
    int e = 0, o = 0;

    for(int i = 0; i < n; i++){
        if(arr[i]%2 == 0){
            even[e] = arr[i];
            e++;
        }
        else{
            odd[o] = arr[i];
            o++;
        }
    }

    printf("The even array is: ");
    for(int i = 0; i < e; i++){
        printf("%d ", even[i]);
    }

    printf("\nThe odd array is: ");
    for(int i = 0; i < o; i++){
        printf("%d ", odd[i]);
    }

    return 0;
}