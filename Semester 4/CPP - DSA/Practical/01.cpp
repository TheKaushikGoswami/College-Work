// Running Sum of 1D Array

#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>& nums){
    vector<int> result;
    int sum = 0;

    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        result.push_back(sum);
    }

    return result;
}

int main(){
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = runningSum(nums);

    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}