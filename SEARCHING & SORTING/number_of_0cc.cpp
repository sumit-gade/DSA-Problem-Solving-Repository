#include <iostream>
using namespace std;

// Function to find the first occurrence of a given element
int firstOcc(int arr[], int n, int x) {
    int s = 0, e = n - 1;
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x) {
            ans = mid;
            e = mid - 1;
        } else if (x < arr[mid]) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

// Function to find the last occurrence of a given element
int lastOcc(int arr[], int n, int x) {
    int s = 0, e = n - 1;
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x) {
            ans = mid;
            s = mid + 1;
        } else if (x < arr[mid]) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

// Function to count the occurrences of a given element
int count(int arr[], int n, int x) {
    // Find the first occurrence of x
    int idxFirst = firstOcc(arr, n, x);

    // If the element does not exist, return 0
    if (idxFirst == -1) {
        return 0;
    }

    // Find the last occurrence of x
    int idxLast = lastOcc(arr, n, x);

    // Return the difference between the last and first
    // occurrences + 1 to get the total count
    return idxLast - idxFirst + 1;
}

// Test example
int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array
    int x = 2; // Element to count
    int result = count(arr, n, x); // Call the count function

    cout << "Element " << x << " occurs " << result << " times in the array." << endl;

    return 0;
}
