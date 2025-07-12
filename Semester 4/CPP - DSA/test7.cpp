#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {
    reverse(s.begin(), s.end());
}

int main(){
    vector<char> s = {'h','e','l','l','o'};
    reverseString(s);
    for(auto i:s){
        cout<<i<<" ";
    }
    return 0;
}

// Output: o l l e h