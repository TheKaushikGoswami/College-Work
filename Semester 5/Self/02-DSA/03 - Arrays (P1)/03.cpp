#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int nums[n];
    
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    
    int smallest = INT_MAX;
    int largest = INT_MIN;

    int smallestIndex = -1;
    int largestIndex = -1;

    int size = sizeof(nums)/ sizeof(nums[0]);

    for(int i=0; i<size; i++){
        if(nums[i] < smallest){
            smallest = nums[i];
            smallestIndex = i;
        }
        if(nums[i] > largest){
            largest = nums[i];
            largestIndex = i;
        }
    }

    cout << "Smallest Index: " << smallestIndex << endl;
    cout << "Largest Index: " << largestIndex << endl;

    return 0;
}