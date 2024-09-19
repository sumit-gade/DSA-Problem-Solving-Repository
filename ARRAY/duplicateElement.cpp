#include <iostream>
#include <vector>
using namespace std;

vector<int> duplicates(vector<int> arr) {
    int n = arr.size();
    
    vector<int> ans;

    // Traverse the array and update counts
    for (int i = 0; i < n; i++) {
        int index = arr[i] % n; // Use the element's value as an index
        arr[index] += n; // Increment the value at that index by n
    }

    // Identify the duplicates
    for (int i = 0; i < n; i++) {
        if (arr[i] / n > 1) { // If the count of an element is more than 1
            ans.push_back(i); // i is the duplicated element
        }
    }

    // If no duplicates found, return {-1}
    if (ans.size() == 0) {
        return {-1};
    }

    return ans;
}

int main() {
    // Example array with duplicates
    vector<int> arr = {1, 2, 3, 6, 3, 6, 1};

    // Call the function to find duplicates
    vector<int> result = duplicates(arr);

    // Output the result
    cout << "Duplicate elements: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
