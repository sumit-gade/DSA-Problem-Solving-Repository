#include <iostream>
using namespace std;

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int n, int k) {
    int start = 0;
    int end = n - 1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == k) {
            return mid; // Target found
        }
        if (arr[mid] < k) {
            start = mid + 1; // Search in the right half
        } else {
            end = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

// Function to print the result of the search
void printSearchResult(int index) {
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }
}

int main() {
    // Example array (must be sorted for binary search)
    int arr[] = {2, 3, 4, 10, 15, 18, 20, 23, 29, 31, 37, 42, 47, 53};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 10; // Element to search for
    
    // Perform search
    int index = binarySearch(arr, n, k);
    printSearchResult(index);

    // Trying to find an element that is not in the array
    k = 5;
    index = binarySearch(arr, n, k);
    printSearchResult(index);

    return 0;
}
