// How to check if a number has an even number of digits

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            if (num >= 10 && num < 100) {
                count++;
            } else if (num >= 1000 && num < 10000) {
                count++;
            } else if (num == 100000) {
                count++;
            }
        }
        return count;
    }
};