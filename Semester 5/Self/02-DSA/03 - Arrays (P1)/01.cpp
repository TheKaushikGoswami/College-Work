#include <bits/stdc++.h>
using namespace std;

int main(){

    int arr[20];

    int marks[5] = {99, 100, 45, 65, 75};

    double price[] = {94.54, 63.45, 234.56};

    cout << marks[3] << endl;

    marks[3] = 43;

    cout << marks[3] << endl;

    int size = sizeof(marks) / sizeof(marks[0]);

    cout << size;

    return 0;
}