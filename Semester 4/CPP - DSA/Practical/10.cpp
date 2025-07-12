// Group Anagrams

#include <bits/stdc++.h>
using namespace std;

void groupAnagrams(vector<string>& strs){
    unordered_map<string, vector<string>> anagramsMap;
    
    for (string s : strs){
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end());
        anagramsMap[sortedStr].push_back(s);
    }

    vector<vector<string>> result;
    for (auto pair : anagramsMap){
        result.push_back(pair.second);
    }

    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(strs);
    return 0;
}