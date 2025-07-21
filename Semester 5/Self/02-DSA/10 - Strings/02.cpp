#include <bits/stdc++.h>
using namespace std;

int main() {
    char str[] = "Hello World";
    int len = 0;

    for(int i=0; str[i]!='\0'; i++){
        len++;
    }

    cout << "Length of string: " << len << endl;
    return 0;
}