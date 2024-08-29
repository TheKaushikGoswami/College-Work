#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int principal, rate, time;
    cout << "Enter principal amount: ";
    cin >> principal;
    cout << "Enter rate of interest: ";
    cin >> rate;
    cout << "Enter time: ";
    cin >> time;

    cout << "Simple interest: " << (principal*rate*time)/100 << endl;
    cout << "Compound interest: " << principal*pow((1+rate/100), time) << endl;

    return 0;
}