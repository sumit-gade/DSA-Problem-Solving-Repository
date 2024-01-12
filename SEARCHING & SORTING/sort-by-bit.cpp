#include <iostream>
#include <algorithm>

// Comparison function to compare integers based on set bit count
static bool comp(int a, int b) {
    return __builtin_popcount(a) > __builtin_popcount(b);
}

// Function to sort an array based on set bit count
void sortBySetBitCount(int arr[], int n) {
    std::stable_sort(arr, arr + n, comp);
}

int main() {
    // Example array
    int arr[] = {5, 2, 8, 14, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    // Sorting the array based on set bit count
    sortBySetBitCount(arr, n);

    std::cout << "\nSorted array by set bit count: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
