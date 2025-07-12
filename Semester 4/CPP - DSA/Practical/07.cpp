// Single Number

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    map<int, int> m;
    for (int n : nums) {
        m[n]++;
    }
    
    for (auto it : m) {
        if (it.second == 1) {
            return it.first;
        }
    }
}

int main(){
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << singleNumber(nums) << endl;
    return 0;
}