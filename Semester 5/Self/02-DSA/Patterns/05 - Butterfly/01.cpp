#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout << "*";
        }
        for(int j=0; j<((2*n)-((i*2)+2)); j++){
            cout << " ";
        }
        for(int j=0; j<i+1; j++){
            cout << "*";
        }
        cout << endl;
    }

    for(int i=0; i<n; i++){
        for(int j=n-i; j>0; j--){
            cout << "*";
        }
        for(int j=0; j<2*i; j++){
            cout << " ";
        }
        for(int j=n-i; j>0; j--){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}