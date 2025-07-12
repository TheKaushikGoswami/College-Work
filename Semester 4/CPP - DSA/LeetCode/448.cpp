// Find All Numbers Disappeared in an Array

class Solution {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            int n = nums.size();
            vector<int> result;
            
            for (int i = 0; i < n; i++) {
                int index = abs(nums[i]) - 1;
                if (nums[index] > 0) {
                    nums[index] = -nums[index];
                }
            }
            
            for (int i = 0; i < n; i++) {
                if (nums[i] > 0) {
                    result.push_back(i + 1);
                }
            }
            
            return result;
        }
};