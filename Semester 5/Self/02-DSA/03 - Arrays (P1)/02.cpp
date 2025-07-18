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

    int size = sizeof(nums)/ sizeof(nums[0]);

    for(int i=0; i<size; i++){
        if(nums[i] < smallest){
            smallest = nums[i];
        }
        largest = max(nums[i], largest);
    }

    cout << "Smallest: " << smallest << endl;
    cout << "Largest: " << largest << endl;

    return 0;
}