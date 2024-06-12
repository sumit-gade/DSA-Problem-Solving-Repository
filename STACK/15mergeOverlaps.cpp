#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    
    // Sort the intervals based on the starting time
    sort(intervals.begin(), intervals.end());
    
    // Push the first interval to the answer list
    ans.push_back(intervals[0]);
    
    // Iterate through each interval starting from the second one
    for (int i = 1; i < intervals.size(); i++) {
        // Check if the current interval overlaps with the last interval in ans
        if (ans.back()[1] >= intervals[i][0]) {
            // Merge the intervals by updating the end time of the last interval in ans
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        } else {
            // If no overlap, add the current interval to ans
            ans.push_back(intervals[i]);
        }
    }
    
    return ans;
}

int main() {
    // Example usage
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> mergedIntervals = overlappedInterval(intervals);
    
    // Print the merged intervals
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    return 0;
}
