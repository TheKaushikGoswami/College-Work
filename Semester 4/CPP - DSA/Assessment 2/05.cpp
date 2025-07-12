// Given string str. The task is to find the maximum occurring character in the string str.
// If there are multiple charcters with maximum frequency, print the character with low ascii value.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    int freq[256] = {0};
    for (int i = 0; i < str.length(); i++) {
        freq[str[i]]++;
    }

    int maxFreq = 0;
    char maxChar;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = i;
        }
    }

    cout << maxChar << endl;

    return 0;
}