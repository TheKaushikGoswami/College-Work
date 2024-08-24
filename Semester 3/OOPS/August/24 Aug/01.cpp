// C++ Program to find remained of a/b where a>b without using % operator

#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a;
    cin >> b;

    int c = a/b;
    int d = a - c*b;

    cout << "Remainder of " << a << "/" << b << " is: " << d << endl;

    return 0;
}