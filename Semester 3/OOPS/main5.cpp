#include <iostream>
using namespace std;

class A{
    public:
        void display(){
            cout << "Class A" << endl;
        }
};

class B{
    public:
        void display2(){
            cout << "Class B" << endl;
        }
};

class C : public B{

};

class D : public B{

};

class E : public A, public C{

};

int main(){
    C obj1;
    D obj2;
    E obj3;
    // obj1.display2();
    // obj2.display2();
    obj3.display();
    obj3.display2();
    return 0;
}