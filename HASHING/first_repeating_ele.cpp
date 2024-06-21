#include <iostream>
#include <unordered_map>
using namespace std;

int firstRepeated(int arr[], int n) {
    unordered_map<int, int> umap;
    
    // First pass: count occurrences of each element
    for (int i = 0; i < n; i++) {
        umap[arr[i]]++;
    }
    
    // Second pass: find the first element with a count greater than 1
    for (int i = 0; i < n; i++) {
        if (umap[arr[i]] > 1) {
            return i + 1; // 1-based index
        }
    }
    
    return -1; // No repeated element found
}

int main() {
    int arr[] = {5, 3, 4, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = firstRepeated(arr, n);
    
    if (result != -1)
        cout << "The first repeated element is at position " << result << endl;
    else
        cout << "There are no repeated elements in the array" << endl;
    
    return 0;
}
