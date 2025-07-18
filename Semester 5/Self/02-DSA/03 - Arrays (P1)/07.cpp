// Calculate Sum & Product of all nums in an array

#include <bits/stdc++.h>
using namespace std;

void fun(int arr[], int size){
    int sum = 0;
    int product = 1;
    for(int i=0; i<size; i++){
        sum+=arr[i];
        product*=arr[i];
    }

    cout << "Sum: " << sum << "\nProduct: " << product << endl;
}

int main(){
    int n;
    cin >> n;
    
    int nums[n];
    
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int size = sizeof(nums)/ sizeof(nums[0]);

    fun(nums, size);

    return 0;
}