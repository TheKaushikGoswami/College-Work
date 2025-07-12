// Valid Anagram

#include <bits/stdc++.h>
using namespace std;

bool isValidAnagram(string s, string t){
    if (s.length() != t.length()){
        return false;
    }

    map<char, int> m1;
    map<char, int> m2;

    for(auto i : s){
        m1[i]++;
    }

    for(auto j : t){
        m2[j]++;
    }

    return m1 == m2;
}

int main(){
    string s = "anagram";
    string t = "nagaram";

    if(isValidAnagram(s,t)) cout << "true";
    else cout << "false";

    return 0;
}