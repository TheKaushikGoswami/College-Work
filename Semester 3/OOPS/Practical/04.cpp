// Implement a class string containing the following functions:
// - Overload + Operator to carry out the concatenation of strings
// - Overload = Operator to carry out string copy
// - Overload <= Operator to carry out the comparison of strings
// - Function to display the length of a string
// - Function to lower() to convert uppercase letters to lowercase
// - Function to upper() to convert lowercase letters to uppercase

#include <iostream>
#include <string>
using namespace std;

class String{
    string s;

    public:
        String(){
            s = "";
        }

        String(string str){
            s = str;
        }

        String operator+(String str){
            return s + str.s;
        }

        void operator=(String str){
            s = str.s;
        }

        bool operator<=(String str){
            return s.length() <= str.s.length();
        }

        void displayLength(){
            cout << "The length of the string is: " << s.length() << endl;
        }

        void lower(){
            for(int i=0; i<s.length(); i++){
                if(s[i] >= 'A' && s[i] <= 'Z'){
                    s[i] += 32;
                }
            }
        }

        void upper(){
            for(int i=0; i<s.length(); i++){
                if(s[i] >= 'a' && s[i] <= 'z'){
                    s[i] -= 32;
                }
            }
        }

        void display(){
            cout << "The string is: " << s << endl;
        }
};

int main(){
    String s1("Hello"), s2("World"), s3;

    s3 = s1 + s2;
    s3.display();

    s3.displayLength();

    s3.lower();
    s3.display();

    s3.upper();
    s3.display();

    return 0;
}
