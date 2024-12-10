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

class E : public A, public C{

};

int main(){
    E obj3;
    obj3.display();
    obj3.display2();
    return 0;
}