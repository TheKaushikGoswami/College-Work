// Quick Sort

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int start, int end){

    int index = start-1, pivot = arr[end];

    for(int j = start; j < end; j++){
        if(arr[j] <= pivot){
            index++;
            swap(arr[j], arr[index]);
        }
    }

    index++;
    swap(arr[end], arr[index]);
    return index;
}

void quickSort(vector<int> &arr, int start, int end){

    if(start < end){

        int pivotIndex = partition(arr, start, end);
    
        quickSort(arr, start, pivotIndex-1);
        quickSort(arr, pivotIndex+1, end);
    }
}

int main() {

    vector<int> arr = {12, 31, 35, 8, 32, 17};
    quickSort(arr, 0, arr.size() - 1);
    
    for( int i : arr){
        cout << i << " ";
    }

    return 0;
}