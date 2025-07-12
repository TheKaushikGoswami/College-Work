// Sort An Array: Given an array of integer nums, sort the array in ascending order using algorithms like quick sort or merge sort.

#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main(){
    vector<int> arr = {5, 2, 3, 1};
    int n = arr.size();

    cout << "Original array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array using Quick Sort: ";
    for (int i : arr) {
        cout << i << " ";
    }

    return 0;
}