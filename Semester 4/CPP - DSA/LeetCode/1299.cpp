// Replace Elements with Greatest Element on the Right Side

class Solution {
    public:
        vector<int> replaceElements(vector<int>& arr) {
            int n = arr.size();
            vector<int> v1(n, -1);
            int maxRight = -1;
            
            for (int i = n - 1; i >= 0; --i) {
                v1[i] = maxRight;
                maxRight = max(maxRight, arr[i]);
            }
            
            return v1;
        }
};