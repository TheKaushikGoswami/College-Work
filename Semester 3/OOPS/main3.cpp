#include <iostream>
using namespace std;

class Human{

    private:
        string religion, caste, race;
    
    protected:
        float salary;
        bool isMarried, isAdult;

    public:
        int age;
        string name;

};

class Student : private Human{

    int marks;
    string course;
    
    public:
        void setData(string name, int age, int marks, string course, bool isAdult){
            this->name = name;
            this->age = age;
            this->marks = marks;
            this->course = course;
            this->isAdult = isAdult;

            // cout << "Data Successfully Added" << endl;
        }

        void getData(){
            cout << name << " " << age << " " << marks << " " << course << " " << "Is Adult: " << isAdult << endl;
        }
};

class Teacher : private Human{
    
    public:
        void setData(string name, int age, float salary, bool isMarried){
            this->name = name;
            this->age = age;
            this->salary = salary;
            this->isMarried = isMarried;

            // cout << "Data Successfully Added" << endl;
        }

        void getData(){
            cout << name << " " << age << " " << salary << " " << "Is Married: " << isMarried << endl;
        }
};

int main(){

    Student s1;
    Student s2;

    Teacher t1;
    Teacher t2;

    s1.setData("Kaushik", 18, 90, "B.Tech", true);
    s2.setData("Shubh", 17, 99, "B.Tech", false);

    t1.setData("Ravi", 25, 45900.32, false);
    t2.setData("Nizam", 40, 50000.42, true);

    s1.getData();
    s2.getData();

    t1.getData();
    t2.getData();

    return 0;

}

