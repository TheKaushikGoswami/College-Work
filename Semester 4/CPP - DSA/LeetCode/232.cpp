// Implement a FIFO queue using only 2 stacks

class MyQueue{
    private:
        stack<int> stack1;
        stack<int> stack2;

    public:
        MyQueue(){
            stack1 = stack<int>();
            stack2 = stack<int>();
        }

        void push(int x){
            stack1.push(x);
        }

        int pop(){
            if (stack2.empty()){
                while(!stack1.empty()){
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            int res = stack2.top();
            stack2.pop();
            return res;
        }

        int peek(){
            if (stack2.empty()){
                while(!stack1.empty()){
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            return stack2.top();
        }

        bool empty(){
            return stack1.empty() && stack2.empty();
        }
}