#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        char c = 'A';
        for(int j=0; j<n; j++){
            cout << c << " ";
            c++;
        }
        cout << endl;
    }

    return 0;
}