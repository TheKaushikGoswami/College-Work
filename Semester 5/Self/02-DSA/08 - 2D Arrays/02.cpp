#include <bits/stdc++.h>
using namespace std;

pair<int, int> linearSearch(int arr[][3], int rows, int cols, int target){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(arr[i][j] == target){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main() {
    int matrix[4][3];
    int rows = 4;
    int cols = 3;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin >> matrix[i][j];
        }
    }

    pair<int, int> result = linearSearch(matrix, rows, cols, 7);
    cout << "{" << result.first << ", " << result.second << "}" << endl;

    return 0;
}
