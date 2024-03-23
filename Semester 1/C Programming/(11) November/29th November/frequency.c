#include <stdio.h>

int main(){

    // C Program to take an array from user and count the frequency of each element

    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter the value of element number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int flag[n];

    for(int i = 0; i < n; i++){
        flag[i] = 0;
    }

    for(int i = 0; i < n; i++){
        if(flag[i] == 1){
            continue;
        }
        int c = 1;
        for(int j = i+1; j < n; j++){
            if(arr[i] == arr[j]){
                c++;
                flag[j] = 1;
            }
        }
        printf("The element %d occurs %d times in the array\n", arr[i], c);
    }

    return 0;
}