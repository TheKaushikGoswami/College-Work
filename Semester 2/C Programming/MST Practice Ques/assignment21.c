#include <stdio.h>

// Write a program to search 12 in following array using linear searchalgorithm. a[10] = { 10, 9, 7, 101, 23, 44, 12, 78, 34, 23};

int linearSearch(int a[], int n, int key){
    for(int i = 0; i<n; i++){
        if(a[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){

    int a[10] = { 10, 9, 7, 101, 23, 44, 12, 78, 34, 23};
    int n = 10;
    int key = 12;

    int index = linearSearch(a, n, key);
    if(index != -1){
        printf("Element found at index %d\n", index);
    }else{
        printf("Element not found\n");
    }

    return 0;

}