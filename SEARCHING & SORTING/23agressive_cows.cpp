#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &stalls, int n, int k, int mid) {
    int cowCount = 1; // Place the first cow in the first stall
    int lastPos = stalls[0]; // The position of the first stall

    for (int i = 1; i < n; i++) { // Start from the second element
        if (stalls[i] - lastPos >= mid) { // Check if the current stall is at least 'mid' away from the last occupied stall
            cowCount++; // Place another cow
            if (cowCount == k) {
                return true; // If all k cows are placed, return true
            }
            lastPos = stalls[i]; // Update the position of the last occupied stall
        }
    }
    return false; // Not possible to place all cows with at least 'mid' distance
}

int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(), stalls.end());

    int s = 1; // smallest possible non-zero distance
    int e = stalls[n - 1] - stalls[0]; // max possible distance from first to last stall
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (isPossible(stalls, n, k, mid)) {
            ans = mid; // found a possible minimum distance
            s = mid + 1; // try for a larger distance
        } else {
            e = mid - 1; // try a smaller distance
        }
    }
    return ans;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9}; // Example stalls
    int n = stalls.size(); // Number of stalls
    int k = 3; // Number of cows to place

    int largestMinDist = solve(n, k, stalls);
    cout << "Largest minimum distance is: " << largestMinDist << endl; // Expected output should be logical according to the spacing of the stalls and number of cows

    return 0;
}
