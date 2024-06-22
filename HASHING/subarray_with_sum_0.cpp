#include <iostream>
#include <unordered_set>

bool subArrayExists(int arr[], int n) {
    std::unordered_set<int> s;
    int pre_sum = 0;
    
    for (int i = 0; i < n; i++) {
        pre_sum += arr[i];
        
        // Check if the current prefix sum is zero
        if (pre_sum == 0) {
            return true;
        }
        
        // Check if the prefix sum has been seen before
        if (s.find(pre_sum) != s.end()) {
            return true;
        }
        
        // Insert the current prefix sum into the set
        s.insert(pre_sum);
    }
    
    return false;
}

int main() {
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (subArrayExists(arr, n)) {
        std::cout << "Subarray with zero sum exists" << std::endl;
    } else {
        std::cout << "Subarray with zero sum does not exist" << std::endl;
    }
    
    return 0;
}
