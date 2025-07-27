// Merge Sort

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end){
    vector<int> temp;

    int i=start, j = mid+1;

    while(i <= mid && j<=end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int index = 0; index<temp.size(); index++){
        arr[index+start] = temp[index];
    }
}

void mergeSort(vector<int> &arr, int start, int end){

    if(start < end){
        int mid = start+(end-start)/2;

        mergeSort(arr, start, mid);
    
        mergeSort(arr, mid+1, end);

        merge(arr, start, mid, end);
    }

}

int main() {

    vector<int> arr = {12, 31, 43, 8, 40, 17};

    mergeSort(arr, 0, arr.size() - 1);

    for(auto i : arr){
        cout << i << " ";
    }

    cout << endl;
    
    return 0;
}