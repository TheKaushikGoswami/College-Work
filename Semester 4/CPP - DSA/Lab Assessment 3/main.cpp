// Project Title: Smart Student Record Manager using C++
// Problem Statement:
// Build a Smart Student Record Manager in C++ that stores, retrieves, and processes academic data for students using a combination of data structures: arrays, linked lists, and maps. The system must allow insertion, searching, sorting, and efficient lookup of student data.

//  Requirements:
// 1. Core Data Structures to Use:
//  Array:

// Store student marks in 5 subjects.

// Use arrays to store sorted lists for quick access/display.

//  Linked List:

// Use a singly linked list to store the list of students in the order they are added.

// Each node should contain a Student object with fields like rollNo, name, marks[5], and average.

//  Map:

// Use std::map<int, Student*> to provide fast search by roll number.

// Acts as an index to quickly retrieve student details.

//  Functional Requirements:
// 1) Add Student

// a) Insert into linked list

// b)Insert into map with roll number as key

// c) Store marks in array and calculate average

// 2) Search Student

// a) By roll number (using map)

// b) By name (traverse linked list)

// c) Display All Students

// d) Display from linked list (in order of addition)

// 3) Sort Students by Average

// a) Extract from linked list into array

// b) Sort array using your own Merge Sort or Quick Sort

// c) Display sorted list

// 4) Generate Reports

// a) Class topper

// b) Subject-wise topper

// c) Students below average

//  Additional Features (Optional):
 
// 1) Save/Load student data using file handling

// 2) Grade generation (A/B/C) based on average

// 3) Menu-driven system for user interaction

// 4) Use a doubly linked list for easier reverse traversal

//  Expected Outcome:
// 1) A working console-based application that:

// 2) Uses linked list for insertion/traversal

// 3) Uses map for fast search

// 4) Uses array for sorting and marks storage

// 5) Demonstrates clean object-oriented code and DSA logic


#include <bits/stdc++.h>
using namespace std;


struct Student {
    long long rollNo;
    string name;
    int marks[5];
    float average;

    void calculateAverage() {
        int sum = 0;
        for(int i = 0; i<5; i++){
            sum += marks[i];
        }
        average = sum / 5.0;
    }
};

struct Node {
    Student* root;
    Node* next;

    Node(Student* s) {
        root = s;
        next = nullptr;
    }
};

Node* head = nullptr;
map<int, Student*> studentMap;

void addStudent() {
    Student* s = new Student;
    cout << "Enter Roll No: ";
    cin >> s->rollNo;
    cout << "Enter Name: ";
    cin.ignore(); // Ignore leftover newline character
    getline(cin, s->name);
    cout << "Enter Marks for 5 subjects: ";
    for(int i = 0; i < 5; i++) {
        cin >> s->marks[i];
    }
    s->calculateAverage();

    Node* newNode = new Node(s);
    if(!head){
        head = newNode;
    }
    else{
        Node* temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    studentMap[s->rollNo] = s;
    cout << "\nStudent added successfully!" << endl;
}

void searchByName() {
    string name;
    cout << "Enter Name to search: ";
    cin.ignore();
    getline(cin, name);

    Node* temp = head;
    while(temp) {
        if(temp->root->name == name) {
            cout << "Roll No: " << temp->root->rollNo << ", Name: " << temp->root->name << ", Average: " << temp->root->average << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "\nStudent not found!" << endl;
}

void displayAll() {
    Node* temp = head;
    while(temp) {
        cout << "Roll No: " << temp->root->rollNo << ", Name: " << temp->root->name << ", Average: " << temp->root->average << endl;
        temp = temp->next;
    }

    if(!head) {
        cout << "\nNo students found!" << endl;
    }
}

void merge(vector<Student*>& arr, int left, int mid, int right) {
    vector<Student*> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<Student*> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while(i < L.size() && j < R.size()) {
        if(L[i]->average <= R[j]->average) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while(i < L.size()) {
        arr[k++] = L[i++];
    }

    while(j < R.size()) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<Student*>& arr, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void sortByAverage() {
    vector<Student*> students;
    Node* temp = head;
    while(temp) {
        students.push_back(temp->root);
        temp = temp->next;
    }

    mergeSort(students, 0, students.size() - 1);

    for(auto s : students) {
        cout << "Roll No: " << s->rollNo << ", Name: " << s->name << ", Average: " << s->average << endl;
    }

    if(students.empty()) {
        cout << "\nNo students found!" << endl;
    }
}

void classTopper() {
    Student* topper = nullptr;
    Node* temp = head;
    while(temp) {
        if(!topper || temp->root->average > topper->average) {
            topper = temp->root;
        }
        temp = temp->next;
    }

    if(topper) {
        cout << "Roll No: " << topper->rollNo << ", Name: " << topper->name << ", Average: " << topper->average << endl;
    } else {
        cout << "\nNo students found!" << endl;
    }
}

void menu() {
    int choice;
    while(true){
        cout << "\n1. Add Student\n2. Search by Name\n3. Display All Students\n4. Sort by Average\n5. Class Topper\n6. Exit\n";
        cin >> choice;

        switch(choice) {
            case 1: addStudent(); break;
            case 2: searchByName(); break;
            case 3: displayAll(); break;
            case 4: sortByAverage(); break;
            case 5: classTopper(); break;
            case 6: exit(0); break;
            default: cout << "Invalid choice!" << endl; break;
        }
    }
}

int main() {
    menu();
    return 0;
}