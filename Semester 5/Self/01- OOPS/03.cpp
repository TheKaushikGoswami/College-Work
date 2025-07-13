#include <bits/stdc++.h>
using namespace std;

class Shape{ // Abstract class
    virtual void draw() = 0; // Pure Virtual Function
};

class Circle : public Shape{

    public:
        void draw(){
            cout << "Drwaing a Circle";
        }
};

int main(){

    Circle c1;
    c1.draw();

    return 0;
}