#include<iostream>
#include<vector>
using namespace std;

pair<long, long> indexes(vector<long long> v, long long x) {
    long s = 0, e = v.size() - 1;
    long first = -1, last = -1; // Initialize the result for first and last occurrences

    // Finding the first occurrence
    while (s <= e) {
        long mid = s + (e - s) / 2;
        if (v[mid] == x) {
            first = mid; // Update first occurrence
            e = mid - 1; // Move left to find the earliest position
        } else if (x < v[mid]) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }

    if (first == -1) {
        // If the element is not found, return {-1, -1}
        return make_pair(-1, -1);
    }

    s = 0, e = v.size() - 1; // Reset search boundaries for the last occurrence

    // Finding the last occurrence
    while (s <= e) {
        long mid = s + (e - s) / 2;
        if (v[mid] == x) {
            last = mid; // Update last occurrence
            s = mid + 1; // Move right to find the latest position
        } else if (x < v[mid]) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }

    return make_pair(first, last);
}

int main() {
    vector<long long> v = {1, 2, 3, 3, 5};
    pair<long, long> result = indexes(v, 3);
    cout << "First occurrence of 3 is at index: " << result.first << endl;
    cout << "Last occurrence of 3 is at index: " << result.second << endl;

    // Example when the element is not present
    result = indexes(v, 4);
    cout << "Occurrences of 4: {" << result.first << ", " << result.second << "}" << endl;

    return 0;
}
