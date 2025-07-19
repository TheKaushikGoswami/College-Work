// Optimized Approach - 2 Pointer

#include <bits/stdc++.h>
using namespace std;

vector<int> pairSum(vector<int> &arr, int target){

    vector<int> v;

    int st = 0, end = arr.size() - 1;

    while(st<end){
        if(arr[st] + arr[end] == target){
            v.push_back(arr[st]);
            v.push_back(arr[end]);
            return v;
        }
        else if(arr[st] + arr[end] > target){
            end--;
        }
        else{
            st++;
        }
    }
}

int main() {

    vector<int> nums = {2, 7, 11, 15};
    int target = 13;

    vector<int> ans = pairSum(nums, target);

    for(auto i : ans){
        cout << i << " ";
    }
    
    return 0;
}