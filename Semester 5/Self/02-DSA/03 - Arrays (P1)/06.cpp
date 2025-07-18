#include <bits/stdc++.h>
using namespace std;

void reverseArr(int arr[], int size){

    // for(int i=0; i<size/2; i++){
    //     swap(arr[i], arr[size-1-i]);
    // }

    int start=0, end=size-1;
    while(start<end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main(){

    int arr[] = {4, 2, 7, 8, 1, 2};

    reverseArr(arr, 6);

    for(int i=0; i<6; i++){
        cout << arr[i] << " ";
    }

    return 0;
}