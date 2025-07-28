// Circular Queue

#include <bits/stdc++.h>
using namespace std;

class CircularQueue{

    int* arr;
    int currentSize, capacity;
    int f, r;

    public:
        CircularQueue(int size){
            capacity = size;
            arr = new int[capacity];
            currentSize = 0;
            f = 0;
            r = -1;
        }

        void push(int val){

            if(currentSize == capacity){
                cout << "Queue is full" << endl;
                return;
            }

            r = (r+1) % capacity;
            arr[r] = val;
            currentSize++;
        }

        void pop(){
            if(empty()){
                cout << "Queue is empty" << endl;
                return;
            }

            f = (f+1) % capacity;
            currentSize--;
        }

        int front(){
            if(empty()){
                cout << "Queue is empty" << endl;
                return -1;
            }
            return arr[f];
        }

        bool empty(){
            return currentSize == 0;
        }

        void printArr(){
            for(int i=0; i<capacity; i++){
                cout << arr[i] << " ";
            }

            cout << endl;
        }
};

int main() {

    CircularQueue cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);

    cq.printArr();

    cq.pop();
    cq.push(4);

    cout << cq.front() << endl;

    cq.printArr();

    while(!cq.empty()){
        cout << cq.front() << " ";
        cq.pop();
    }
    
    return 0;
}