// You are given a string s.

// Your task is to remove all digits by doing this operation repeatedly:

// Delete the first digit and the closest non-digit character to its left.
// Return the resulting string after removing all digits.

// Note that the operation cannot be performed on a digit that does not have any non-digit character to its left.

 

// Example 1:

// Input: s = "abc"

// Output: "abc"

// Explanation:

// There is no digit in the string.

// Example 2:

// Input: s = "cb34"

// Output: ""

// Explanation:

// First, we apply the operation on s[2], and s becomes "c4".

// Then we apply the operation on s[1], and s becomes "".

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
    public:
        string clearDigits(string s) {
            stack<char> st;
            for (int i = 0; i < s.size(); i++) {
                if (isdigit(s[i])) {
                    if (!st.empty()) {
                        st.pop();
                    }
                } else {
                    st.push(s[i]);
                }
            }
            string res = "";
            while(!st.empty()) {
                res += st.top();
                st.pop();
            }
            return res;
        }
}

int main() {
    Solution s;
    cout << s.clearDigits("abc") << endl;
    cout << s.clearDigits("cb34") << endl;
    return 0;
}