// Valid Mountain Array

class Solution {
    public:
        bool validMountainArray(vector<int>& arr) {
            bool reversed = false;
            bool flag = false;
    
            if(arr.size() < 3){
                return false;
            }
    
            for(int i=1; i<arr.size(); i++){
                if(!reversed){
                    if(arr[i] <= arr[i-1]){ // Ensure strictly increasing
                        if(i == 1) return false; // Peak cannot be the first element
                        reversed = true;
                        flag = true; // Mark that a peak was found
                    }
                }
                if(reversed){
                    if(arr[i] >= arr[i-1]){ // Ensure strictly decreasing
                        return false;
                    }
                }
            }
            return reversed && flag; // Ensure there was a peak and a valid mountain
            return flag;

        }
}