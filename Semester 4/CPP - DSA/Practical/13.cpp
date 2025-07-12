// Evaluate Reverse Polish Notation

#include <bits/stdc++.h>
using namespace std;

bool isOperator(string s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int evaluateRPN(vector<string>& tokens) {
    stack<int> st;
    for (const string& token : tokens) {
        if (isOperator(token)) {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") st.push(a / b);
        } else {
            st.push(stoi(token));
        }
    }
    return st.top();
}

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << evaluateRPN(tokens) << endl;
    return 0;
}