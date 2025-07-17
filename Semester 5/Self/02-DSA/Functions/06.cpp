#include <bits/stdc++.h>
using namespace std;

int nthFibonacci(int x){
    if (x <= 1) return x;
    int a = 0, b = 1, c;
    for (int i = 2; i <= x; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(){

    int n;
    cin >> n;

    cout << nthFibonacci(n);

    return 0;
}