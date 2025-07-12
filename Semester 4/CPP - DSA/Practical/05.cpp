// Top K Frequent Elements

#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> countMap;
    for (int num : nums) {
        countMap[num]++;
    }

    vector<pair<int, int>> freqList(countMap.begin(), countMap.end());
    sort(freqList.begin(), freqList.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    vector<int> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(freqList[i].first);
    }
    return result;
}

int main(){
    vector<int> nums = {1, 1, 1, 2, 3, 3, 4};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}