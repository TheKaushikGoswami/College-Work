#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    string filtered;
    for (char c : s) {
        if (isalnum(c)) {
            filtered += tolower(c);
        }
    }
    string reversed = filtered;
    reverse(reversed.begin(), reversed.end());
    return filtered == reversed;
}

int main() {
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s);
    return 0;
}

