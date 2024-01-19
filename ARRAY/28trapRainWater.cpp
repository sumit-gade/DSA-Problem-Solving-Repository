#include<iostream>
using namespace std;

long long trappingWater(int arr[], int n) {
    // Left Max Array
    int lmax[n];
    lmax[0] = arr[0];
    for (int i = 1; i < n; i++) {
        int temp = max(arr[i], lmax[i - 1]);
        lmax[i] = temp;
    }

    // Right Max Array
    int rmax[n];
    rmax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        int temp = max(arr[i], rmax[i + 1]);
        rmax[i] = temp;
    }

    // Calculate Trapped Water
    long long water = 0;
    for (int i = 1; i < n - 1; i++) {
        water += min(lmax[i], rmax[i]) - arr[i];
    }

    return water;
}


int main() {
    int arr[] = {3, 0, 0, 2, 0, 4}; // Example input array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    long long result = trappingWater(arr, n); // Call the trappingWater function

    // Display the result
    std::cout << "Trapped water: " << result << " units." << std::endl;

    return 0;
}