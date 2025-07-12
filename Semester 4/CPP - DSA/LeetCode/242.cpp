#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mp;
    int left = 0, right = 0, maxLength = 0;
    while (right < s.size()) {
        if (mp.find(s[right]) != mp.end()) {
            left = max(left, mp[s[right]] + 1);
        }
        mp[s[right]] = right;
        maxLength = max(maxLength, right - left + 1);
        right++;
    }
    return maxLength;
}

int main(){
    string s = "abcabcbb";
    cout<<lengthOfLongestSubstring(s);
    return 0;
}