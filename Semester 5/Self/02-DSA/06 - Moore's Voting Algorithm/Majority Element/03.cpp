// Moore's Voting Algorithm

int majorityElement(vector<int>& nums) {

    int c = 0, ans = 0;

    for(int i = 0; i<n; i++){
        if(c == 0){
            ans = nums[i];
        }
        if(ans == nums[i]){
            c++;
        }
        else{
            c--;
        }
    }

    return ans;
        
}