#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    // for(int i=0; i<n; i++){
    //     int num = i+1;
    //     for(int j=0; j<i+1; j++){
    //         cout << num << " ";
    //         num--;
    //     }
    //     cout << endl;
    // }

    for(int i=0; i<n; i++){
        for(int j=i+1; j>0; j--){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}