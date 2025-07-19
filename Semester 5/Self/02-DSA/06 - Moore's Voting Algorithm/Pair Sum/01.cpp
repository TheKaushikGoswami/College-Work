// Return pair in sorted arra with target sum

// Brute Force

#include <bits/stdc++.h>
using namespace std;

vector<int> pairSum(vector<int> &nums, int target){

    vector<int> v;

    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i] + nums[j] == target){
                v.push_back(nums[i]);
                v.push_back(nums[j]);
            }
        }
    }

    return v;
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