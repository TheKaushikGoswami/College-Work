// Find the greatest of 2 given numbers in two different classes using friend function.

#include <iostream>
using namespace std;

class B;

class A{
    int a;

    public:
        void getA(){
            cout << "Enter the value of a: ";
            cin >> a;
        }

        friend void greatest(A, B);
};

class B{
    int b;

    public:
        void getB(){
            cout << "Enter the value of b: ";
            cin >> b;
        }

        friend void greatest(A, B);
};

void greatest(A a, B b){
    if(a.a > b.b){
        cout << "The greatest number is: " << a.a << endl;
    }else{
        cout << "The greatest number is: " << b.b << endl;
    }
}

int main(){
    A a;
    B b;

    a.getA();
    b.getB();

    greatest(a, b);

    return 0;
}