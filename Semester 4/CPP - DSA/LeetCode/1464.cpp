// Maximum Product of Two Elements in an Array

class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int maxProduct = INT_MIN;
            for(int i=0; i<nums.size(); i++){
                for(int j=i+1; j<nums.size(); j++){
                    if(((nums[i]-1)*(nums[j]-1)) > maxProduct){
                        maxProduct = (nums[i]-1)*(nums[j]-1);
                    }
                }
            }
    
            return maxProduct;
        }
};