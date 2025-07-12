// Map Sort by Values

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    map<int, int> m;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        m[x] = y;
    }

    map<int, vector<int>> m1;
    for(auto i : m){
        m1[i.second].push_back(i.first);
    }

    cout << "Sorted by Values:" << endl;

    for(auto i : m1){
        for( auto p : i.second){
            cout << p << " " << i.first << endl;
        }
    }

    return 0;
}