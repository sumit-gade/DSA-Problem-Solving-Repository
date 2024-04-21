#include <iostream>
#include <algorithm>

// Function to count the number of triplets with a sum less than a given value
long countTriplets(int arr[], int n, long sum) {
    // Sort the array
    std::sort(arr, arr + n);
    long count = 0;

    // Iterate through the array, fixing the first element of the triplet
    for (int i = 0; i < n - 2; i++) {
        int j = i + 1; // Start of the second element
        int k = n - 1; // Start of the third element

        // Use the two-pointer technique to find pairs with the desired condition
        while (j < k) {
            long long S = arr[i] + arr[j] + arr[k]; // Sum of the triplet

            if (S < sum) { // If the sum is less than the target value
                count += (k - j); // All pairs (j, j+1, ..., k) will have a sum less than `sum`
                j++; // Move the second pointer to the right
            } else {
                k--; // Otherwise, move the third pointer to the left to reduce the sum
            }
        }
    }

    return count; // Return the total count of triplets with sum less than `sum`
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6}; // Sample array
    int n = sizeof(arr) / sizeof(arr[0]);
    long sum = 10; // Target sum

    long result = countTriplets(arr, n, sum);

    std::cout << "Number of triplets with a sum less than " << sum << ": " << result << std::endl;

    return 0; // End of program
}
