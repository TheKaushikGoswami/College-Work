#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x){
    for (int i=2; i<x/2; i++){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}

void printPrimes(int x){

    for(int i = 2; i<= x; i++){
        if(isPrime(i)){
            cout << i << endl;
        }
    }
}

int main(){

    int n;
    cin >> n;

    printPrimes(n);

    return 0;
}