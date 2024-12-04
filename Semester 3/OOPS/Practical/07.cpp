// Demonstrate the use of special functions, constructor and destructor in the class template. The program is used to find the bigger of two entered numbers.

#include <iostream>
using namespace std;

template <class T>
class Bigger{
    T a, b;

    public:
        Bigger(T x, T y){
            a = x;
            b = y;
        }

        void display(){
            cout << "The bigger number is: " << (a > b ? a : b) << endl;
        }

        ~Bigger(){
            cout << "Destructor called." << endl;
        }
};

int main(){
    Bigger<int> b1(5, 10);
    b1.display();

    Bigger<float> b2(5.5, 10.5);
    b2.display();

    return 0;
}