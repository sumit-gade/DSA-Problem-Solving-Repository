#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long max_sum = INT_MIN;
    long long current_sum = 0;

    for (int i = 0; i < n; ++i) {
        current_sum += arr[i];

        // If current_sum becomes negative, reset it to 0
        if (current_sum < 0) {
            current_sum = 0;
        }

        // Update max_sum if current_sum is greater
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    return max_sum;
}

// Example usage:
int main() {
    int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    long long result = maxSubarraySum(arr, n);
    cout << "Maximum subarray sum is: " << result << endl;

    return 0;
}
