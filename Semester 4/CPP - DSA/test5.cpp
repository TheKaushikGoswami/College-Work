// Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

// For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
// Return the resulting string.

 

// Example 1:

// Input: word = "abcdefd", ch = "d"
// Output: "dcbaefd"
// Explanation: The first occurrence of "d" is at index 3. 
// Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
// Example 2:

// Input: word = "xyxzxe", ch = "z"
// Output: "zxyxxe"
// Explanation: The first and only occurrence of "z" is at index 3.
// Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".
// Example 3:

// Input: word = "abcd", ch = "z"
// Output: "abcd"
// Explanation: "z" does not exist in word.
// You should not do any reverse operation, the resulting string is "abcd".

// Using Stack

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
    public:
        string reversePrefix(string word, char ch) {

            stack<char> s;
            int index = -1;
            for (int i = 0; i < word.size(); i++) {
                if (word[i] == ch) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                return word;
            }

            for(int i = 0; i <= index; i++) {
                s.push(word[i]);
            }

            string res = "";

            while(!s.empty()) {
                res += s.top();
                s.pop();
            }

            for(int i = index + 1; i < word.size(); i++) {
                res += word[i];
            }

            return res;
        }
};

int main() {
    Solution solution;
    cout << solution.reversePrefix("abcdefd", 'd') << endl; // Example 1
    cout << solution.reversePrefix("xyxzxe", 'z') << endl;  // Example 2
    cout << solution.reversePrefix("abcd", 'z') << endl;    // Example 3
    return 0;
}