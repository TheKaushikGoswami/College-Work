// Maximum Subarray Sum

// 2. Kadane's Algorithm

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    int arr[5] = {-1, -2, -3, -4, -5};

    int maxSum = INT_MIN;
    int currentSum = 0;

    for(int i=0; i<n; i++){
        currentSum += arr[i];
        maxSum = max(currentSum, maxSum);

        if(currentSum < 0){
            currentSum = 0;
        }
    }

    cout << maxSum;

    return 0;
}