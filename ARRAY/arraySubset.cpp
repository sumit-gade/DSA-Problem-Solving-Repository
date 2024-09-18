#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    
    // Create an empty unordered_map to store the elements of a1
    unordered_map<int, int> map;
    
    // Dump all a1 elements into the map and count occurrences
    for (int i = 0; i < n; i++) {
        map[a1[i]]++; // Increment count of each element
    }
    
    // Loop through a2
    for (int j = 0; j < m; j++) {
        // Check if each element of a2 is present in the map
        if (map[a2[j]] <= 0) {
            return "No"; // If even one element of a2 is missing in a1, return "No"
        }
        else {
            map[a2[j]]--; // Decrement the count for duplicate elements
        }
    }
    
    return "Yes"; // All elements of a2 are found in a1
}

int main() {
    // Example arrays
    int a1[] = {1, 2, 3, 4, 5};
    int a2[] = {2, 3, 4};

    int n = sizeof(a1) / sizeof(a1[0]);
    int m = sizeof(a2) / sizeof(a2[0]);

    // Call the function and print the result
    cout << "Is a2 a subset of a1? " << isSubset(a1, a2, n, m) << endl;

    return 0;
}
