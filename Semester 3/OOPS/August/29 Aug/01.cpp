#include <iostream>
using namespace std;

int main(){
    float a;

    cout<<"Enter a number: ";
    cin>>a;

    int b = a;

    cout << "Decimal part of " << a << " is: " << a-b << endl;

    return 0;
}