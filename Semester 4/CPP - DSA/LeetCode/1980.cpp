#include <bits/stdc++.h>
using namespace std;

map <string, int> mp;

void solve(int n, int i, string res){
    if(i==n){
        mp[res]++;
        return;
    }

    solve(n, i+1, res+"0");
    solve(n, i+1, res+"1");
}

int main(){
    int n;
    cin>>n;

    vector <string> v1;
    string s;

    for(int i=0; i<n; i++){
        cin>>s;
        v1.push_back(s);
    }

    for(auto p: v1){
        mp[p]++;
    }

    solve(n, 0, "");

    for(auto it:mp){
        if(it.second==1){
            cout << it.first;
            break;
        }
    }

    return 0;
}