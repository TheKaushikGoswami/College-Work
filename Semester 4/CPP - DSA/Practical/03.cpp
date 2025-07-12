// Min Stack

#include <bits/stdc++.h>
using namespace std;

class MinStack{
    stack<int> s;
    stack<int> minStack;

    public:

        void push(int x) {
            s.push(x);
            if (minStack.empty() || x <= minStack.top()) {
                minStack.push(x);
            }
        }

        void pop() {
            if (s.top() == minStack.top()) {
                minStack.pop();
            }
            s.pop();
        }

        int top() {
            return s.top();
        }

        int getMin() {
            return minStack.top();
        }
};

int main(){
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;

    return 0;
}