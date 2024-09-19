#include <iostream>
using namespace std;

int peakElement(int arr[], int n) {
    // Base case: If there's only one element, it's the peak
    if (n == 1) {
        return 0;
    }
    
    // Check for peak at the first element
    if (arr[0] >= arr[1]) {
        return 0;
    }
    
    // Check for peak at the last element
    if (arr[n-1] >= arr[n-2]) {
        return n-1;
    }
    
    // Check for peak in the middle of the array
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) {
            return i;
        }
    }
    
    // Fallback in case no peak is found (though in a valid input, there will be a peak)
    return -1;
}

int main() {
    // Example array
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Call the function to find the peak element
    int peakIndex = peakElement(arr, n);
    
    // Output the result
    if (peakIndex != -1) {
        cout << "The peak element is at index: " << peakIndex << " and its value is: " << arr[peakIndex] << endl;
    } else {
        cout << "No peak element found" << endl;
    }
    
    return 0;
}
