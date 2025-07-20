#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 10;
    cout << &a << endl;

    int *ptr = &a;

    cout << ptr << endl;

    int **ptr2 = &ptr;

    cout << ptr2 << endl;

    int *ptr3 = NULL;

    cout << ptr3;

    return 0;
}