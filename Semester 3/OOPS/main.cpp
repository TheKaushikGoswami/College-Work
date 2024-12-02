#include <iostream>
using namespace std;

class Student{
    // private by default
    int roll, marks;
    string name;

    public:

        // Default Constructor

        Student(){
            cout << "A default constructor was called" << endl;
            roll = 32;
            marks = 99;
            name = "Test";
        }

        // Parameterized Constructor

        // Student(string n, int a, int b){
        //     cout << "A parameterized constructor was called" << endl;
        //     name = n;
        //     roll = a;
        //     marks = b;
        // }

        Student(string name, int roll, int marks){
            cout << "-----------------\nA parameterized constructor (with 'this' pointer) was called" << endl;
            this->name = name;
            this->roll = roll;
            this->marks = marks;
        }

        // Constructor Overloading

        Student(string a){
            cout << "-----------------\nThis Constructor displays constructor overloading" << endl;
            name = a;
        }

        // Inline Constructor

        inline Student(string a, int b): name(a), roll(b){cout << "-----------------\nThis is an Inline Constructor" << endl;};

        // Copy Constructor

        Student(Student &A){
            cout << "-----------------\nThis is a Copy Constructor call" << endl;
            name = A.name;
            roll = A.roll;
            marks = A.marks;
        }

        ~Student(){
            cout << "-----------------\nThe Destructor was Called" << endl;
        }
            
        // getter functions

        void getName(){
            cout << name << endl;
        }

        void getMarks(){
            cout << marks << endl;
        }

        void getRoll(){
            cout << roll << endl;
        }
        
        // setter functions

        void setName(string n){
            name = n;
        }

        void setMarks(int m){
            marks = m;
        }

        void setRoll(int r){
            roll = r;
        }
    
};

int main(){
    // s1.name = "Test";
    // s1.roll = 1234;
    // s1.marks = 90;

    // s1.setRoll(1032);
    // s1.setName("Kaushik");
    // s1.setMarks(90);

    // s1.getRoll();
    // s1.getName();
    // s1.getMarks();

    Student s1;
    Student s5(s1);
    s5.getRoll();
    s5.getName();
    s5.getMarks();

    // s1.getRoll();
    // s1.getName();
    // s1.getMarks();

    // Student s2("Test 2", 20, 100);

    // s2.getRoll();
    // s2.getName();
    // s2.getMarks();

    // Student s3("Test 3");

    // s3.getName();
    // // s3.getRoll();
    // // s3.getMarks();

    // Student s4("Test 4", 120);
    
    // s4.getRoll();
    // s4.getName();


    return 0;
}