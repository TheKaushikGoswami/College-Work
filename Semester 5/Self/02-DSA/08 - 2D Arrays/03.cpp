#include <bits/stdc++.h>
using namespace std;

int getMaxSum(int arr[][3], int rows, int cols){

    int maxSum = INT_MIN;

    for(int i=0; i<rows; i++){
        int sum = 0;
        for(int j=0; j<cols; j++){
            sum+=arr[i][j];
        }
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main() {
    
    int matrix[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

    cout << getMaxSum(matrix, 3, 3) << endl;
    return 0;
}