// Duplicate Zeroes

class Solution {
    public:
        void duplicateZeros(vector<int>& arr) {
            
            int n = arr.size();
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] == 0) {
                    count++;
                }
            }
            for (int i = n - 1, j = n + count - 1; i >= 0; i--) {
                if (j < n) {
                    arr[j] = arr[i];
                }
                if (arr[i] == 0) {
                    j--;
                    if (j < n) {
                        arr[j] = 0;
                    }
                }
                j--;
            }
            
        }
    };