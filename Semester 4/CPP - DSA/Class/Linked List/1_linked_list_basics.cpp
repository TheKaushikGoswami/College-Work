// Linked List

#include <iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
};

int main(){
    Node *a;
    Node *b;
    Node *c;
    Node *head;

    a = new Node();
    b = new Node();
    c = new Node();

    a->val = 10;
    b->val = 20;
    c->val = 30;

    head=a;

    a->next = b;
    b->next = c;
    c->next = NULL;

    while(head!=NULL){
        cout<<head->val<<" ";
        head = head->next;
    }

    return 0;
}