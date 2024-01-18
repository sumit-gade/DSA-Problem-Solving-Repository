#include <iostream>
#include <vector>

int majorityElement(std::vector<int>& nums) {
    int candidate = INT_MIN;
    int life = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate) {
            // If the same number is encountered, increment the 'life' count.
            life++;
        } else if (life == 0) {
            // If 'life' becomes 0, assign the current number as the candidate and reset 'life' to 1.
            candidate = nums[i];
            life = 1;
        } else {
            // If a different number is encountered, decrement the 'life' count.
            life--;
        }
    }

    return candidate;
}

int main() {
    // Example array: {2, 2, 1, 1, 1, 2, 2}
    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    // Find the majority element using the provided function
    int result = majorityElement(nums);

    // Print the result
    std::cout << "Majority Element: " << result << std::endl;

    return 0;
}
