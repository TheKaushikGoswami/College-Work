#include <stdio.h>

int main(){

    // C Program to take an array from user and then take an element from user and count the number of times that element occurs in the array

    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter the value of element number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int a;
    printf("Enter the element to be searched: ");
    scanf("%d", &a);

    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == a){
            count++;
        }
    }

    printf("The element %d occurs %d times in the array", a, count);

    return 0;

}