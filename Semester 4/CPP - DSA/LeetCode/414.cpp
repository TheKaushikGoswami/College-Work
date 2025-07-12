// Third Maximum Number

class Solution {
    public:
        int thirdMax(vector<int>& nums) {
            set<int> ans(nums.begin(), nums.end());
            if(ans.size() < 3){
                return *ans.rbegin();
            }
    
            return *next(ans.rbegin(), 2);
        }
};