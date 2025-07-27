#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }
};

class List{
    Node* head;
    Node* tail;

    public:
        List(){
            head = tail = NULL;
        }

        void push_front(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = tail = newNode;
                return;
            }
            else{
                newNode->next = head;
                head = newNode;
                return;
            }

        }

        void push_back(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = tail = newNode;
                return;
            }
            else{
                tail->next = newNode;
                tail = newNode;
                return;
            }
        }

        void pop_front(){
            if(head!=NULL){
                Node* temp = head;
                head = head->next;
                temp->next = NULL;
                delete temp;
            }
            else{
                cout << "Empty Linked List" << endl;
                return;
            }
        }

        void pop_back(){
            if(head!=NULL){
                Node* temp = head;
                while(temp->next != tail){
                    temp = temp->next;
                }
                temp->next = NULL;
                delete tail;
                tail = temp;

                // while(temp->next->next != NULL){
                //     temp = temp->next;
                // }
                // temp->next = NULL;
                // delete temp->next;
            }
            else{
                cout << "Empty Linked List" << endl;
                return;
            }
        }

        void insert(int val, int pos){
            if(pos == 0){
                push_front(val);
                return;
            }

            Node* temp = head;                
            for(int i=0; i<pos-1; i++){
                if(temp == NULL){
                    cout << "Invalid Position" << endl;
                    return;
                }
                temp = temp->next;
            }


            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }

        void search(int val){
            Node* temp = head;
            int idx = -1;
            while(temp!=NULL){
                idx++;
                if(temp->data == val){
                    cout << "Value found at index: " << idx << endl;
                    return;
                }
                temp = temp->next;
            }
            
            cout << "Value not found" << endl;
            return;
        }

        void display(){
            Node* temp = head;
            while(temp!=NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {

    List l;

    l.push_front(1);
    l.push_front(3);
    l.push_front(2);
    l.push_back(10);
    
    l.display();

    l.pop_front();
    l.pop_back();

    l.display();

    l.insert(4, 1);

    l.display();

    l.search(1);

    return 0;
}