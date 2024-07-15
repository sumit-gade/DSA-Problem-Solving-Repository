#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> findTwoElement(vector<int> arr, int n) {
    vector<int> res(2, 0); // Initialize result vector with two elements
    
    for (int i = 0; i < n; i++) {
        if (arr[abs(arr[i]) - 1] > 0) { // If positive number
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1]; // Mark as visited by making it negative
        } else {
            res[0] = abs(arr[i]); // Repeated element
        }
    }
    
    // Now all visited elements are negative
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) { // If positive, then its index + 1 is the missing element
            res[1] = i + 1; // Missing element
        }
    }
    
    return res;
}

int main() {
    vector<int> arr = {4, 3, 6, 2, 1, 1}; // Example array
    int n = arr.size();
    
    vector<int> result = findTwoElement(arr, n);
    
    cout << "Repeated element: " << result[0] << endl;
    cout << "Missing element: " << result[1] << endl;
    
    return 0;
}
