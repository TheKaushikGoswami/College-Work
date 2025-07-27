#include <bits/stdc++.h>
using namespace std;

class Stack{
    list<int> l;

    public:

    void push(int val){
        l.push_front(val);
    }

    void pop(){
        l.pop_front();
    }

    int top(){
        return l.front();
    }

    bool empty(){
        return l.size() == 0;
    }
};

int main() {

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
    
    return 0;
}