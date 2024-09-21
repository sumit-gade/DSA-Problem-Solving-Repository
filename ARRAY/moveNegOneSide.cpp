#include <iostream>
#include <vector>
using namespace std;

void segregateElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp; // Temporary vector to store segregated elements

    // First, store all positive numbers while maintaining their order
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {  // Also include zero as a positive element
            temp.push_back(arr[i]);
        }
    }

    // Then, store all negative numbers while maintaining their order
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            temp.push_back(arr[i]);
        }
    }

    // Copy the temporary array back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    vector<int> arr = {1, -1, 3, 0, -2, 5, -7, 8, -3};
    
    segregateElements(arr);
    
    cout << "Array after segregation: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

