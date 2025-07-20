#include <bits/stdc++.h>
using namespace std;

void changeA(int &a){
    a = 12;
}

int main() {
    int a = 10;

    changeA(a);

    cout << a << endl;
    return 0;
}