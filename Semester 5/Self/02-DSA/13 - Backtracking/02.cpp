// Calculate permutations of a string

#include <bits/stdc++.h>
using namespace std;

void getPermutations(string s, int index, vector<string> &ans){
        if(index == s.size()){
            ans.push_back(s);
            return;
        }

        for(int i=index; i<s.size(); i++){
            swap(s[index], s[i]);
            getPermutations(s, index+1, ans);

            swap(s[index], s[i]);
        }
    }

vector<string> permute(string s) {
    vector<string> ans;
    getPermutations(s, 0, ans);
    return ans;
}

int main(){

    string s = "abcd";
    vector<string> v = permute(s);

    for(auto i : v){
        cout << i << " ";
    }

    return 0;
}