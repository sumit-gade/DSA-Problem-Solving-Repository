#include <iostream>
#include <unordered_map>
#include <vector>

int findElement(const std::vector<int>& a, int k) {
    std::unordered_map<int, int> mp;

    // Count the frequency of each element in the array
    for (int i = 0; i < a.size(); i++) {
        mp[a[i]]++;
    }

    // Check for an element whose frequency is not a multiple of k
    for (auto x : mp) {
        if (x.second % k != 0)
            return x.first;
    }

    // Return -1 if no such element is found
    return -1;
}

int main() {
    std::vector<int> a = {1, 2, 3, 2, 3, 1, 1}; // Example array
    int k = 2; // Example k value

    int result = findElement(a, k);
    std::cout << "Element not appearing a multiple of " << k << " times: " << result << std::endl;

    return 0;
}
