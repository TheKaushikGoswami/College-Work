// Write a C++ program to do the following:
// 1. Take an user input for no. of elements in vector
// 2. Insert the elements in vector
// 3. Insert the values in the nodes of linked list
// 4. Find the sum of all members of linked list
// 5. Find the mid of linked list

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int p){
            val=p;
            next=NULL;
        }
};

int main(){
    // Task 1
    int n;
    cout << "Enter the number of elements in vector: ";
    cin>>n;

    // Task 2
    vector<int> v(n);
    cout << "Enter the elements of vector: ";
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    // Task 3
    Node *root, *head;
    root = new Node(v[0]);
    head = root;

    for(int i=1; i<n; i++){
        Node *ptr = new Node(v[i]);
        head->next = ptr;
        head = ptr;
    }

    // Task 4
    head = root;
    int sum = 0;
    while(head != NULL){
        sum += head->val;
        head = head->next;
    }

    cout << "Sum of all members of linked list: " << sum << endl;

    // Task 5
    head = root;

    return 0;
}