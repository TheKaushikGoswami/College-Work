#include <bits/stdc++.h>
using namespace std;

void isPrime(int x){
    for (int i=2; i<x/2; i++){
        if(x%i == 0){
            cout << "Not Prime";
            return;
        }
    }

    cout << "Prime";
    return;
}

int main(){

    int n;
    cin >> n;

    isPrime(n);

    return 0;
}