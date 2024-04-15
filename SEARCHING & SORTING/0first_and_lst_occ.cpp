#include<bits/stdc++.h> 
#include<vector>

using namespace std;

vector<int> find(int arr[], int n, int x) {
    int start = 0, end = n - 1;
    vector<int> result;

    // Find the first occurrence
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == x && (mid == 0 || arr[mid - 1] != x)) {
            result.push_back(mid);
            break;
        } else if (arr[mid] < x) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    // Find the last occurrence
    start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == x && (mid == n - 1 || arr[mid + 1] != x)) {
            result.push_back(mid);
            break;
        } else if (arr[mid] <= x) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    if (result.empty()) {
        return {-1,-1}; // Element not found
    } else {
        sort(result.begin(), result.end());
        return {result[0], result[result.size() - 1]};
    }
}

int main() {
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 5, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;

    vector<int> result = find(arr, n, x);

    if (result[0] == -1 && result[1] == -1) {
        cout << "Element " << x << " not found in the array." << endl;
    } else {
        cout << "First occurrence of " << x << " is at index " << result[0] << endl;
        cout << "Last occurrence of " << x << " is at index " << result[1] << endl;
    }

    return 0;
}
