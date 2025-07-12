#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int pD = 0, sD = 0;

    for(int i = 0; i < n; i++) {
        pD += matrix[i][i];
        for(int j = 0; j < m; j++) {
            if(i + j == n - 1) {
                sD += matrix[i][j];
            }
        }
    }

    cout << "Primary: " << pD << endl;
    cout << "Secondary: " << sD << endl;

    return 0;
}