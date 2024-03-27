#include <stdio.h>

// Write a program in C to sort the following array in ascending order 
// a[10] = { 10, 9, 7, 101, 23, 44, 12, 78, 34, 23}; Using 
// Bubble Sort
// Selection sort 
// Insertion sort

void bubbleSort(int a[], int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void selectionSort(int a[], int n){
    for(int i = 0; i<n-1; i++){
        int min = i;
        for(int j = i+1; j<n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void insertionSort(int a[], int n){
    for(int i = 1; i<n; i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

/* Function to print an array */

void printArray(int a[], int n){
    for(int i = 0; i<n; i++){
        printf("%d, ", a[i]);
    }
    printf("\n");
}

int main(){

    int a[10] = { 10, 9, 7, 101, 23, 44, 12, 78, 34, 23};
    int n = 10;

    printf("The array before sorting is: ");
    printArray(a, n);

    bubbleSort(a, n);
    printf("The array after Bubble Sort is: ");
    printArray(a, n);

    int b[10] = { 10, 9, 7, 101, 23, 44, 12, 78, 34, 23};
    selectionSort(b, n);
    printf("The array after Selection Sort is: ");
    printArray(b, n);

    int c[10] = { 10, 9, 7, 101, 23, 44, 12, 78, 34, 23};
    insertionSort(c, n);
    printf("The array after Insertion Sort is: ");
    printArray(c, n);

    return 0;

}