#include <iostream>
#include <vector>
#include <algorithm> // For max function
using namespace std;

vector<int> leaders(int n, int arr[]) {
    vector<int> ans;

    // Suffix array to store the maximum element to the right (including current element)
    int suffix[n];
    suffix[n-1] = arr[n-1]; // Last element is always a leader

    // Fill the suffix array from right to left
    for (int i = n-2; i >= 0; i--) {
        suffix[i] = max(arr[i], suffix[i+1]);
    }

    // Identify the leaders
    for (int i = 0; i < n; i++) {
        if (arr[i] == suffix[i]) {
            ans.push_back(arr[i]);
        }
    }

    return ans;
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> result = leaders(n, arr);

    // Output the leaders
    cout << "Leaders in the array are: ";
    for (int leader : result) {
        cout << leader << " ";
    }

    return 0;
}
