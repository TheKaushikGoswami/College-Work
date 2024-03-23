#include <stdio.h>
int main(){

    // C Program to take an array from user and then print sum of all the elements given by user

    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter the value of element number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int sum = 0;

    for(int i = 0; i < n; i++){
        sum+=arr[i];
    }

    printf("The sum of all elements of the array is: %d", sum);

    return 0;

}