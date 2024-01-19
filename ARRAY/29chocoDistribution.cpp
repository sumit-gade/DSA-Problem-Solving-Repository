#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m) {
    sort(a.begin(), a.end()); // Use a.begin() and a.end() for vectors

    long long minDiff = LLONG_MAX; // LLONG_MAX is used for long long type

    for (long long i = 0; i + m - 1 < n; i++) {
        long long d = a[i + m - 1] - a[i];

        if (d < minDiff) {
            minDiff = d; // Fix the typo here, change 'mind' to 'minDiff'
        }
    }

    cout << minDiff << endl;

    return minDiff; // Return the minimum difference
}

int main() {
    // Example usage
    vector<long long> arr = {3, 9, 7, 3}; // Example input vector
    long long n = arr.size(); // Calculate the size of the vector
    long long m = 2; // Example value for m

    long long result = findMinDiff(arr, n, m); // Call the findMinDiff function

    return 0;
}
