#include <iostream>
#include <algorithm>

// Function to find if there's a pair with a given difference in a sorted array
bool findPair(int arr[], int size, int n) {
    // Sort the array
    std::sort(arr, arr + size);

    int i = 0;
    int j = 1;

    // Use a two-pointer technique to find a pair with the given difference
    while (i < size && j < size) {
        if (i != j && std::abs(arr[j] - arr[i]) == n) {
            return true; // Found a pair with the desired difference
        }

        // If the difference is less than 'n', increment 'j' to increase the difference
        if (std::abs(arr[j] - arr[i]) < n) {
            j++;
        } else {
            // Otherwise, increment 'i' to decrease the difference
            i++;
        }
    }

    return false; // No pair with the given difference was found
}

int main() {
    int arr[] = {1, 5, 3, 4, 2}; // Sample array
    int size = sizeof(arr) / sizeof(arr[0]);
    int n = 3; // Desired difference

    bool hasPair = findPair(arr, size, n);

    if (hasPair) {
        std::cout << "There is a pair with a difference of " << n << " in the array." << std::endl;
    } else {
        std::cout << "No pair with a difference of " << n << " found in the array." << std::endl;
    }

    return 0;
}
