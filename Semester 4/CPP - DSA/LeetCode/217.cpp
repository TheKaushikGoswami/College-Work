#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_map <int, int> m;
            for(int i = 0; i < nums.size(); i++){
                m[nums[i]]++;
            }
    
            for(auto it:m){
                if(it.second > 1){
                    return true;
                }
            }
    
            return false;
        }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,1};
    cout << s.containsDuplicate(nums);
    return 0;
}