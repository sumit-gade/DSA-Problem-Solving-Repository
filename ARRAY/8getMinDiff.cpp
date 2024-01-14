#include <algorithm>
#include <iostream>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
    sort(arr, arr + n);
    int minVal = arr[0];
    int maxVal = arr[n - 1];
    int ans = maxVal - minVal;

    for (int i = 1; i < n; i++) {
        int a = arr[i - 1] + k;
        int b = arr[i] - k;

        if (b < 0)
            continue;

        minVal = min(a, b);
        maxVal = max(arr[i - 1] + k, arr[i] - k);

        ans = max(ans, maxVal - minVal);
    }

    return ans;
}

int main() {
    int arr[] = {1, 10, 14, 14, 14, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;

    int result = getMinDiff(arr, n, k);
    cout << "Minimum difference is: " << result << endl;

    return 0;
}
