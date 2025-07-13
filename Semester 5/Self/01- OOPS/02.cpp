#include <bits/stdc++.h>
using namespace std;

class Person{
    public:
        string name;
        int age;
    
        Person(string name, int age){
            this->name = name;
            this->age = age;
            cout << "Person constructor" << endl;
        }
        
        ~Person(){
            cout << "Person destructor" << endl;
        }
};

class Student : public Person{
    public:
        int roll;

        Student(string name, int age, int roll) : Person(name, age) {
            this->roll = roll;
            cout << "Child Constructor" << endl;
        }

        ~Student(){
            cout << "Child Destructor" << endl;
        }

        void getInfo(){
            cout << name << endl << age << endl << roll << endl;
        }
};

int main(){

    Student s1("Kaushik", 19, 5323);
    // s1.name = "Kaushik";
    // s1.age = 19;
    // s1.roll = 5323;

    s1.getInfo();

    return 0;
}