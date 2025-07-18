#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector<int> vec1;

    vector<int> vec2 = {1, 2, 3};

    vector<int> v3(3, 0);

    vector<char> v = {'a', 'b', 'c'};

    cout << "Size: " << v.size() << endl;

    v.push_back('d');

    for(char c : v){
        cout << c << " ";
    }

    cout << endl;

    v.pop_back();

    for(char c : v){
        cout << c << " ";
    }

    cout << endl;
    
    cout << v.front() << endl;

    cout << v.back() << endl;

    cout << v.at(1) << endl;

    return 0;
}