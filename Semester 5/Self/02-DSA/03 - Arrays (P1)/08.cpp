// Swap the max & min number of an array

#include <bits/stdc++.h>
using namespace std;

void swapMinAndMax(int nums[], int size){
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int smallestIndex = -1;
    int largestIndex = -1;

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

    int temp = smallest;
    nums[smallestIndex] = largest;
    nums[largestIndex] = smallest;

}


int main(){
    int n;
    cin >> n;
    
    int nums[n];
    
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int size = sizeof(nums)/ sizeof(nums[0]);

    swapMinAndMax(nums, size);

    for(int i=0; i<size; i++){
        cout << nums[i] << " ";
    }

    return 0;
}