#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=i; j>=0; j--){
            cout << char('A'+j) << " ";
        }
        cout << endl;
    }

    return 0;
}