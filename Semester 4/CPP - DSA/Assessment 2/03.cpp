// Write a C++ program to convert a given non-negative integer into English words.

#include <iostream>
#include <string>
using namespace std;

string convert(int num) {
    string result = "";
    string below_20[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    if(num == 0) {
        return "Zero";
    }
    else if (num < 20) {
        result += below_20[num];
    } else if (num < 100) {
        result += tens[num / 10] + " " + below_20[num % 10];
    } else if (num < 1000) {
        result += below_20[num / 100] + " Hundred " + convert(num % 100);
    } else if (num < 100000) {
        result += convert(num / 1000) + " Thousand " + convert(num % 1000);
    } else if (num < 10000000) {
        result += convert(num / 100000) + " Lakh " + convert(num % 100000);
    } else {
        result += convert(num / 10000000) + " Crore " + convert(num % 10000000);
    }

    return result;
}

int main() {
    int num;
    cin >> num;

    cout << convert(num) << endl;

    return 0;
}