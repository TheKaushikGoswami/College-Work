// Optimize - By Sorting

int majorityElement(vector<int>& nums) {

    int c = 1, ans = nums[0];

    for(int i = 1; i<n; i++){
        if(nums[i] == nums[i-1]){
            c++;
        }
        else{
            c=1;
            ans = nums[i];
        }

        if(c>nums.size()/2){
            return ans;
        }
    }

    return ans;        
}