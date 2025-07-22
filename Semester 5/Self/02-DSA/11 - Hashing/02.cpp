// Find Missing and Repeated Values

class Solution{
public:
    vector<int> findMissingAndRepeating(vector<int> &arr, int n) {
        vector<int> result(2);
        for (int i = 0; i < n; i++) {
            int index = abs(arr[i]) - 1;
            if (arr[index] < 0) {
                result[0] = abs(arr[i]);
            } else {
                arr[index] = -arr[index];
            }
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                result[1] = i + 1;
                break;
            }
        }
        return result;
    }
}