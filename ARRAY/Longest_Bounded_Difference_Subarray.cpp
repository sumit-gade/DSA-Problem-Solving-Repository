#include <bits/stdc++.h>
using namespace std;

vector<int> longestSubarray(vector<int>& arr, int x) {
    int n = arr.size();
    int left = 0, max_len = 0;
    multiset<int> window; // Stores elements of the current subarray
    vector<int> best_yet; // Stores the longest valid subarray found

    for (int right = 0; right < n; right++) {
        window.insert(arr[right]);

        // Shrink the window if the difference between max and min exceeds x
        while (*window.rbegin() - *window.begin() > x) {
            window.erase(window.find(arr[left]));
            left++;
        }

        // Update the longest subarray found
        if (right - left + 1 > max_len) {
            max_len = right - left + 1;
            best_yet = vector<int>(arr.begin() + left, arr.begin() + right + 1);
        }
    }
    return best_yet;
}

int main() {
    vector<int> arr = {8, 2, 4, 7, 5, 1, 9, 6};
    int x = 3; // Maximum allowed difference between min and max in the subarray

    vector<int> result = longestSubarray(arr, x);

    cout << "Longest subarray with max difference <= " << x << " is: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
