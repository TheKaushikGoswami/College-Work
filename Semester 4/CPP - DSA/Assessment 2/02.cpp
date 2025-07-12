// Write a C++ program to insert a dash character (-) between two odd numbers in a given string of numbers.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    for (int i = 0; i < str.length() - 1; i++) {
        if (isdigit(str[i]) && isdigit(str[i + 1])) {
            if ((str[i]) % 2 != 0 && (str[i + 1]) % 2 != 0) {
                str.insert(i + 1, "-");
                i++;
            }
        }
    }

    cout << str << endl;

    return 0;
}