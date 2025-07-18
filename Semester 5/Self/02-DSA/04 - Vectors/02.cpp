// Reverse a Vector

#include <bits/stdc++.h>
using namespace std;

void reverseVector(vector<int>& nums) {
    int s = nums.size();

    for(int i=0; i<s/2; i++){
        swap(nums[i], nums[s-1-i]);
    }

}

int main() {

    vector<int> v = {5, 6, 7, 8, 9, 0};

    reverseVector(v);

    for(int i : v){
        cout << i << " ";
    }
    
    return 0;
}