// Write a C++ program to remove all special characters from a given string.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    for (int i = 0; i < str.length(); i++) {
        if (!isalnum(str[i])) {
            str.erase(i, 1);
            i--;
        }
    }

    cout << str << endl;

    return 0;
}