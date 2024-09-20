#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> getPairs(vector<int>& arr) {
    // Set to store unique pairs in sorted order
    set<vector<int>> unique_pairs;
    unordered_map<int, int> freq;  // To store the frequency of elements

    // Traverse the array
    for (int i = 0; i < arr.size(); i++) {
        // Check if there is a number in the map such that arr[i] + that number = 0
        int complement = 0 - arr[i];
        
        // If complement exists in map, then add all such unique pairs to the result
        if (freq.find(complement) != freq.end()) {
            // Insert the pair in sorted order into the set (this will automatically handle duplicates)
            unique_pairs.insert({min(arr[i], complement), max(arr[i], complement)});
        }
        
        // Increment the frequency of arr[i]
        freq[arr[i]]++;
    }
    
    // Convert the set of unique pairs back into a vector
    vector<vector<int>> pairs(unique_pairs.begin(), unique_pairs.end());
    
    return pairs;
}
int main() {
    vector<int> arr = {1, -1, 2, -2, 3, -3, 1, -1};
    vector<vector<int>> result = getPairs(arr);
    
    // Print pairs
    for (const auto& pair : result) {
        cout<<" "endl;
    }

    return 0;
}
