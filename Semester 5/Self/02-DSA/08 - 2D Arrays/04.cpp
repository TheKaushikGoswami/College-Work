#include <bits/stdc++.h>
using namespace std;

int getColSum(int arr[][3], int rows, int cols){

    int maxSum = INT_MIN;

    for(int i=0; i<rows; i++){
        int sum = 0;
        for(int j=0; j<cols; j++){
            sum+=arr[j][i];
        }
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main() {
    
    int matrix[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

    cout << getColSum(matrix, 3, 3) << endl;
    return 0;
}