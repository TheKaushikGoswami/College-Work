#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 10;
    int *ptr = &a;

    cout << ptr << endl;
    ptr++;
    cout << ptr << endl;
    ptr--;
    cout << ptr << endl;

    int *ptr2;
    int *ptr3 = ptr2+4;

    cout << ptr3 - ptr2 << endl;

    cout << (ptr2>ptr3) <<  endl;
    cout << (ptr2<ptr3) <<  endl;
    cout << (ptr2!=ptr3) <<  endl;

    return 0;
}