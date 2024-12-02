// Perform addition of two complex numbers using constructor overloading. The first constructor which takes no argument is used to create objects which are not initialized, second which takes one argument is used to initialize real and imaginary parts to equal values and thirs which takes two arguments is to initialized real and imago to two different values.

#include <iostream>
using namespace std;

class Complex{
    int real, imaginary;

    public:
        Complex(){
            real = 0;
            imaginary = 0;
        }

        Complex(int r){
            real = r;
            imaginary = r;
        }

        Complex(int r, int i){
            real = r;
            imaginary = i;
        }

        void display(){
            cout << "The complex number is: " << real << " + " << imaginary << "i" << endl;
        }
};

int main(){
    Complex c1, c2(5), c3(3, 4);
    c1.display();
    c2.display();
    c3.display();
    return 0;
}
