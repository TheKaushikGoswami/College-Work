#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> mat = {{1,2,3}, {4,5,6}, {7,8,9}};

    // rows = mat.size();
    // cols = mat[i].size();

    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[i].size(); j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    mat[1].push_back(10);
    mat[1].push_back(11);

    cout << endl;

    for(auto i : mat){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}