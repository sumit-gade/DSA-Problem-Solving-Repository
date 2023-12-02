// ye to ulta wala rotate hai 


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            temp[(i + k) % nums.size()] = nums[i];
        }

        // Copy the rotated elements back to the original vector
        nums = temp;
    }
};

int main() {
  
    Solution solution;
    
   
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    
    // Rotate the vector to the right by 2 positions
    solution.rotate(nums, 2);

    // Display the rotated vector
    cout << "Rotated vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
