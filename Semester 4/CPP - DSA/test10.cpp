#include <bits/stdc++.h>
using namespace std;

int noOfWords(string s){
    int count = 0;

    for(int i = 0; i < s.length(); i++) {
        if(s[i+1] == ' ' && s[i] != ' ') {
            count++;
        }
    }

    return count;
}

int main() {
    string s;
    getline(cin, s);
    int words = noOfWords(s);
    cout << "Number of words: " << words + 1 << endl;
    return 0;
}