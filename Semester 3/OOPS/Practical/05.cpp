// Create a class called LIST with 2 pure virtual function store() and retrieve(). To store a value, call store and to retrieve, call retrieve function. Derive 2 classes stack and queue from it and override store and retrieve.

#include <iostream>
using namespace std;

class LIST{
    public:
        virtual void store() = 0;
        virtual void retrieve() = 0;
};

class stack: public LIST{
    int a[10], top;

    public:
        stack(){
            top = -1;
        }

        void store(){
            if(top == 9){
                cout << "The stack is full." << endl;
                return;
            }

            cout << "Enter the value to be stored: ";
            cin >> a[++top];
        }

        void retrieve(){
            if(top == -1){
                cout << "The stack is empty." << endl;
                return;
            }

            cout << "The value retrieved is: " << a[top--] << endl;
        }
};

class queue: public LIST{
    int a[10], front, rear;

    public:
        queue(){
            front = rear = -1;
        }

        void store(){
            if(rear == 9){
                cout << "The queue is full." << endl;
                return;
            }

            cout << "Enter the value to be stored: ";
            cin >> a[++rear];
        }

        void retrieve(){
            if(front == rear){
                cout << "The queue is empty." << endl;
                return;
            }

            cout << "The value retrieved is: " << a[++front] << endl;
        }
};

int main(){
    LIST *l;
    stack s;
    queue q;

    l = &s;
    cout << "Stack:" << endl;
    l->store();
    l->store();
    l->retrieve();
    l->retrieve();

    l = &q;
    cout << endl << "Queue:" << endl;
    l->store();
    l->store();
    l->retrieve();
    l->retrieve();

    return 0;
}
