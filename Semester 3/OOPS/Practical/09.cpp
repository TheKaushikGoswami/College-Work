// Read the class object of student info such as name, age, sex, height and weight from the keyboard and to store them on a specified file using read() and write() functions. Again the same file is opened for reading and displaying the contents of the file on the screen.

#include <iostream>
#include <fstream>
using namespace std;

class Student {
    char name[100]; // Fixed-size array for the name
    int age;

public:
    void read() {
        cout << "Enter the name of the student (no spaces): ";
        cin >> name; // Basic cin stops at spaces
        cout << "Enter the age of the student: ";
        cin >> age; // Basic cin for integers
    }

    void write() {
        ofstream fout("student.txt", ios::app); // Open file in append mode
        if (!fout) {
            cout << "Error opening file for writing!" << endl;
            return;
        }
        fout << "Name: " << name << ", Age: " << age << endl;
        fout.close();
    }

    void display() {
        ifstream fin("student.txt"); // Open file for reading
        if (!fin) {
            cout << "Error opening file for reading!" << endl;
            return;
        }
        char ch;
        cout << "\nContents of the file:\n";
        while (fin.get(ch)) { // Read one character at a time
            cout << ch;
        }
        fin.close();
    }
};

int main() {
    Student s;
    s.read();
    s.write();
    s.display();
    return 0;
}
