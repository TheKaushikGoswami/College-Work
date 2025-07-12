// Ordered Map

// #include <iostream>
// #include <map>
// #include <string>
// using namespace std;

// int main(){
//     map <string, int> mp;
//     mp["abc"] = 1;
//     mp["def"] = 2;
//     mp["ghi"] = 3;
//     mp["jkl"] = 4;
    
// }


// Write a C++ program to calculate the frequency of each number in the array and print the number and its frequency.


#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    map <int, int> mp;
    vector <int> v;

    int n, x;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }

    for(int i = 0; i < n; i++){
        mp[v[i]]++;
    }

    for(auto it : mp){
        cout << it.first << "-->" << it.second << endl;
    }

    return 0;
}