#include <iostream>
using namespace std;

class Student{
    string name;
    int roll;

    // Static Data Member
    static int total_students;

    public:
        Student(string name, int roll){
            this->name = name;
            this->roll = roll;
            total_students++; // Incrementing the total count
        }

        // Static Data Function
        static void display_count(){
            cout << total_students;
        }
    
        void display(){
            cout << name << " " << roll << " " << endl;
        }
};

int Student :: total_students = 0;

int main()
{
    Student s1("Kaushik", 1032);
    s1.display();

    Student s2("Shubh", 1027);
    s2.display();

    Student :: display_count();
    // Student :: total_students = 10;  // Only accessible when the static data type is in public

}