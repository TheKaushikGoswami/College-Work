// Maximum Subarray

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN, currentSum = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        currentSum += nums[i];
        maxSum = max(maxSum, currentSum);
        
        if (currentSum < 0) {
            currentSum = 0;
        }
    }
    
    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = maxSubArray(nums);
    
    cout << result << endl;
    
    return 0;
}