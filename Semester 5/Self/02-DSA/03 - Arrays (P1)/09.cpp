// Print all unique values in an array

#include <bits/stdc++.h>
using namespace std;

void printUniques(int arr[], int size){
    for(int i=0; i<size; i++){
        int count = 0;
        for(int j=0; j<size; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count == 1){
            cout << arr[i] << " ";
        }
    }
}

int main(){
    int n;
    cin >> n;
    
    int nums[n];
    
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int size = sizeof(nums)/ sizeof(nums[0]);

    printUniques(nums, size);

    return 0;
}