#include <iostream>
#include <vector>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
    vector<long long int> left(n), right(n);
    
    // Initialize left and right arrays
    left[0] = 1;
    right[n - 1] = 1;
    
    // Construct the left array
    for (int i = 1; i < n; i++)
        left[i] = nums[i - 1] * left[i - 1];
    
    // Construct the right array
    for (int i = n - 2; i >= 0; i--)
        right[i] = nums[i + 1] * right[i + 1];
    
    // Construct the product array using left[] and right[]
    for (int i = 0; i < n; i++)
        nums[i] = left[i] * right[i];
    
    return nums;
}

int main() {
    vector<long long int> nums = {1, 2, 3, 4};
    int n = nums.size();
    
    vector<long long int> result = productExceptSelf(nums, n);
    
    cout << "Original Array: ";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;
    
    cout << "Product Except Self: ";
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
    cout << endl;
    
    return 0;
}
