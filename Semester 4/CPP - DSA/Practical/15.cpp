// Pascal's Triangle

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle(numRows);
    for (int i = 0; i < numRows; i++) {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1; // First and last element of each row is 1
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j]; // Fill in the rest of the row
        }
    }
    return triangle;
}

int main() {
    int numRows = 5;
    vector<vector<int>> triangle = generate(numRows);
    for (const auto& row : triangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}