// Define the function template for calculating the square of given numbers with different data types.

#include <iostream>
using namespace std;

template <class T>
T square(T n){
    return n * n;
}

int main(){
    cout << "The square of 5 is: " << square(5) << endl;
    cout << "The square of 5.5 is: " << square(5.5) << endl;
    return 0;
}
