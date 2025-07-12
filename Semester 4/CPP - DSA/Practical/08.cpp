// Transpose of a matrix

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> transposed(cols, vector<int>(rows));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    return transposed;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> result = transpose(matrix);
    
    for (auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}