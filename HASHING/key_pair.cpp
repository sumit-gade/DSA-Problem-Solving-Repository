#include <iostream>
#include <unordered_map>

bool hasPairWithSum(int arr[], int n, int x) {
    std::unordered_map<int, int> umap;
    
    // Populate the unordered map with the frequency of each element
    for (int i = 0; i < n; i++) {
        umap[arr[i]]++;
    }
    
    // Iterate through the map to find if a pair exists
    for (auto itr = umap.begin(); itr != umap.end(); itr++) {
        int key = itr->first;
        int val = itr->second;
        
        int pair = x - key;
        if (pair == key) {
            // Special case when the pair consists of two identical elements
            if (val > 1) {
                return true;
            }
        } else {
            // General case
            if (umap.find(pair) != umap.end()) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    int arr[] = {1, 4, 5, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;

    if (hasPairWithSum(arr, n, x)) {
        std::cout << "Array has a pair with the given sum" << std::endl;
    } else {
        std::cout << "Array does not have a pair with the given sum" << std::endl;
    }
    
    return 0;
}
