#include <stdio.h>
int main(){
    
    // C Program to take an array from user and print array in reverse format

    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter the value of element number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("The array in reverse order is: ");

    for(int i = n-1; i >=0; i--){
        printf("%d ", arr[i]);
    }

    return 0;

}