#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n==1){
        return 1;
    }

    return n * factorial(n-1);
}

int main() {
    cout << factorial(2);
    return 0;
}