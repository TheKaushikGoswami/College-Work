#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    string temp = s;
    reverse(s.begin(), s.end());
    return s==temp;
}

int main() {
    string s = "racecar";
    cout << isPalindrome(s);
    return 0;
}