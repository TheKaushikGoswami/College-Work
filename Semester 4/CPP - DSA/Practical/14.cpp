// Design Circular Queue

#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
    public:
        vector<int> queue;
        int front, rear, size, capacity;

        MyCircularQueue(int k) {
            capacity = k;
            queue.resize(k);
            front = -1;
            rear = -1;
            size = 0;
        }

        bool enQueue(int value) {
            if (isFull()) return false;
            if (isEmpty()) front = 0;
            rear = (rear + 1) % capacity;
            queue[rear] = value;
            size++;
            return true;
        }

        bool deQueue() {
            if (isEmpty()) return false;
            front = (front + 1) % capacity;
            size--;
            if (isEmpty()) {
                front = -1;
                rear = -1;
            }
            return true;
        }

        int Front() {
            if (isEmpty()) return -1;
            return queue[front];
        }

        int Rear() {
            if (isEmpty()) return -1;
            return queue[rear];
        }

        bool isEmpty() {
            return size == 0;
        }

        bool isFull() {
            return size == capacity;
        }
};

int main(){
    
    MyCircularQueue circularQueue = MyCircularQueue(3);
    cout << circularQueue.enQueue(1) << endl; // return true
    cout << circularQueue.enQueue(2) << endl; // return true
    cout << circularQueue.enQueue(3) << endl; // return true
    cout << circularQueue.enQueue(4) << endl; // return false, the queue is full
    cout << circularQueue.Rear() << endl; // return 3
    cout << circularQueue.isFull() << endl; // return true
    cout << circularQueue.deQueue() << endl; // return true
    cout << circularQueue.enQueue(4) << endl; // return true
    cout << circularQueue.Rear() << endl; // return 4

    return 0;
}