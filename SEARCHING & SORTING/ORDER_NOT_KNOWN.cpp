#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int k) {
    bool isAscending = (arr[0] <= arr[n-1]);
    
    cout << (isAscending ? "Array is ascending." : "Array is descending.") << endl;

    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == k) {
            return mid; // Target found
        }

        if (isAscending) {
            if (arr[mid] < k) {
                start = mid + 1; // Search in the right half
            } else {
                end = mid - 1; // Search in the left half
            }
        } else {
            if (arr[mid] > k) {
                start = mid + 1; // Search in the right half (for descending )
            } else {
                end = mid - 1; // Search in the left half (for descending )
            }
        }
    }
    
    return -1; // Element not found
}

int main() {
    int arr[] = {10, 6, 4, 2, 1, 0}; // Example of a descending ed array
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    int result = binarySearch(arr, n, k);

    if (result == -1) {
        cout << "Element not found." << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }

    return 0;
}
