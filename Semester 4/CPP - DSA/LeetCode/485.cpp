// Max Consecutive Ones

class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int maxCount = 0, count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 1) {
                    count++;
                } else {
                    maxCount = max(maxCount, count);
                    count = 0;
                }
            }
            return max(maxCount, count);
        }
};