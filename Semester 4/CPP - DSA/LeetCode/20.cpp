class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
    
            for (char c : s) {
                if (!st.empty() && abs(st.top() - c) <=2 && abs(st.top() - c) != 0 && st.top() < c) {
                    st.pop();
                } else {
                    st.push(c);
                }
            }
    
            if(!st.empty()){
                return false;
            }
    
            return true;
        }
};