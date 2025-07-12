// Flipped Up
// Yash has a n x n binary matrix. Raj was angry at Yash and flipped his matrix up. 


// Now he wants to retrieve his original matrix. He hands you this task and then leaves to find Raj to flip his matrix.


// To retrieve the original matrix you have to flip each row of the matrix horizontally, then invert it, and print the resulting matrix.


// Flip a row horizontally means that each row of the matrix is reversed. For example, flipping [1,1,0,1] horizontally results in [0,0,1,0].

// Inverting a matrix means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0,1,0,0] results in [1,0,1,1].


// Input format

// The first contains integer n.

// The next n lines contain n space-separated bits.


// Output format

// n lines containing n space-separated bits.


// Example 1

// Input

// 3
// 1 1 0
// 1 0 1
// 0 0 0


// Output

// 1 0 0
// 0 1 0
// 1 1 1


// Explanation

// First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].

// Then, invert the matrix: [[1,0,0],[0,1,0],[1,1,1]]


// Constraints

// n == matrix.length

// n == matrix[i].length

// 1 <= n <= 20

// matrix[i][j] is either 0 or 1.

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=n-1; j>=0; j--){
            cout << 1-matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}