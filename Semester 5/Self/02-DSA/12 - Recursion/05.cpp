// Check if array is sorted

#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> arr, int n){
    if(n==0 || n==1){
        return true;
    }

    return arr[n-1] >= arr[n-2] && isSorted(arr, n-1);
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    cout << isSorted(v, 5);
    return 0;
}