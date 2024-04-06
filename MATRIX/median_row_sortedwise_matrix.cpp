#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int median(vector<vector<int>> &matrix, int R, int C) {
    int mi = INT_MAX;   // Initializing min and max
    int mx = INT_MIN;

    for (int i = 0; i < R; i++) {
        mi = min(mi, matrix[i][0]);      // Min number first el
        mx = max(mx, matrix[i][C - 1]);  // Max el last number
    }

    int ans;

    while (mi <= mx) {
        int mid = mi + (mx - mi) / 2;

        int freq = 0;

        for (int i = 0; i < R; i++) {
            // Find all the counts which are smaller than mid
            freq += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if (freq >= (R * C + 1) / 2) {
            ans = mid;
            mx = mid - 1;
        } else {
            mi = mid + 1;
        }
    }
    return ans;
}

int main() {
    // Example usage
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    int R = 3, C = 3;
    cout << "Median: " << median(matrix, R, C) << endl;
    return 0;
}
