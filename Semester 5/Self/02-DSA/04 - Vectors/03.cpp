// Linear Search in Vector

#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& nums, int target) {

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == target) {
            return i;
        }
    }

    return -1;

}

int main() {

    vector<int> v = {5, 6, 7, 8, 9, 0};
    int target = 8;

    cout << linearSearch(v, target);
    
    return 0;
}