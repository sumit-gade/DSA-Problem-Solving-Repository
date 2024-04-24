#include <iostream>
using namespace std;

// Function to perform binary search on a sorted array
int ReversebinarySearch(int arr[], int n, int k) {
    int start = 0;
    int end = n - 1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == k) {
            return mid; // Target found
        }
        if (arr[mid] < k) {
             end = mid - 1;
             
        } else {
            start = mid + 1;
            
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
    int arr[] = {77,65,45,38,21,15,7,8,4,3,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 10; // Element to search for
    
    // Perform search
    int index =ReversebinarySearch(arr, n, k);
    printSearchResult(index);

    // Trying to find an element that is in the array
    k = 7;
    index = ReversebinarySearch(arr, n, k);
    printSearchResult(index);

    return 0;
}