#include <iostream>
#include <algorithm> // For sort function

using namespace std;

// Function to merge arrays
void merge(long long arr1[], long long arr2[], int n, int m) {
    int i = n - 1;
    int j = 0;
    
    // Swap elements to make sure all elements in arr1 are less than or equal to arr2
    while (i >= 0 && j < m) {
        if (arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
        }
        
        i--;
        j++; 
    }

    // Sort both arrays to maintain sorted order
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

// Function to print array elements
void printArray(long long arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    long long arr1[] = {10, 15, 20, 30};
    long long arr2[] = {1, 5, 8, 12, 14, 18};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    // Print original arrays
    cout << "Original arr1: ";
    printArray(arr1, n);
    cout << "Original arr2: ";
    printArray(arr2, m);

    // Merge the arrays
    merge(arr1, arr2, n, m);

    // Print modified arrays
    cout << "Modified arr1: ";
    printArray(arr1, n);
    cout << "Modified arr2: ";
    printArray(arr2, m);

    return 0;
}
