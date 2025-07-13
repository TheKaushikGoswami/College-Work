#include <bits/stdc++.h>
using namespace std;

class Teacher {

    private:
        double salary;

    public:
        string name;
        string dept;
        string subject;

        // Non-Parameterised
        Teacher(){
            dept = "Computer Science";
        }

        // Parameterised
        Teacher(string name, string dept, string subject, double salary){
            this->name = name;
            this->dept = dept;
            this->subject = subject;
            this->salary = salary;
        }

        // Copy Constructor (Shallow)
        Teacher(Teacher &obj){
            this->name = obj.name;
            this->dept = obj.dept;
            this->subject = obj.subject;
            this->salary = obj.salary;
        }


        void setSalary(double newSal){
            salary = newSal;
        }

        void getSalary(){
            cout << salary << endl;
        }

        void getInfo(){
            cout << name << endl << dept << endl << subject << endl << salary << endl;
        }
};

class Student{
    public:
        string name;
        // double cgpa;
        double *cgpaPtr;

        Student(string name, double cgpa){
            this->name = name;
            cgpaPtr = new double;
            *cgpaPtr = cgpa;
        }

        Student(Student &obj){
            this->name = obj.name;
            cgpaPtr = new double;
            *cgpaPtr = *obj.cgpaPtr;
        }

        ~Student(){
            delete cgpaPtr;
            cout << "Destroyer Destructed" << endl;
        }

        void getInfo(){
            cout << name << endl << *cgpaPtr << endl;
        }
};

int main() {

    Teacher t1("Kaushik", "Computer Science", "C++", 30000);
    // t1.name = "Kaushik";
    // t1.subject = "C++";

    // t1.setSalary(25000);

    // cout << t1.dept << endl;

    // t1.getSalary();

    t1.getInfo();

    Student s1("Kaushik Goswami", 8.8);
    s1.getInfo();
    Student s2(s1);
    *(s2.cgpaPtr) = 9.2;
    s2.getInfo();

    return 0;
}