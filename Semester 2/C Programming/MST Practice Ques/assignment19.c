#include <stdio.h>
#include <stdlib.h>

// Write a Program to make an array using malloc() and print the elements of it. Resize and deallocate the memory allocated dynamically

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The elements of the array are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Enter the new size of the array: ");
    scanf("%d", &n);
    arr = (int *)realloc(arr, n * sizeof(int));
    if (arr == NULL) {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The elements of the array are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}