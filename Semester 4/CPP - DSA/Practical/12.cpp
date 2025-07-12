// Merge Intervals

#include <bits/stdc++.h>
using namespace std;

void mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return;

    // Sort the intervals based on the start time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        // If the current interval overlaps with the last merged interval, merge them
        if (intervals[i][0] <= merged.back()[1]) {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            // Otherwise, add the current interval to the merged list
            merged.push_back(intervals[i]);
        }
    }

    // Print the merged intervals
    for (const auto& interval : merged) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    mergeIntervals(intervals);
    return 0;
}