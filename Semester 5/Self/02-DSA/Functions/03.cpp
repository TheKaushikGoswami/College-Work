#include <bits/stdc++.h>
using namespace std;

int factorial(int x){
    int fact = 1;
    for(int i = 1; i<=x; i++){
        fact*=i;
    }

    return fact;
}

int calculateBinomialCoeff(int n, int r){

    return (factorial(n)/(factorial(r)*factorial(n-r)));

}

int main(){

    int n, r;
    cin >> n >> r;

    cout << calculateBinomialCoeff(n, r);

    return 0;
}