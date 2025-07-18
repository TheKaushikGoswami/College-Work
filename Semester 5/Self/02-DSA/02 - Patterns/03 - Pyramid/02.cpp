#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        char ch = 'A';
        for(int j=0; j<n-i-1; j++){
            cout << " ";
        }
        for(int j=0; j<i+1; j++){
            cout << char(ch+j);
        }
        for(int j=i; j>0; j--){
            cout << char(ch+j-1);
        }
        cout << endl;
    }

    return 0;
}