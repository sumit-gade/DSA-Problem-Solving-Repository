#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap; // Map to store next greater elements
        stack<int> st; // Stack to help find next greater elements
        int n = nums2.size();

        // Traverse nums2 from right to left
        for (int i = n - 1; i >= 0; i--) {
            int ele = nums2[i];

            // Maintain elements in the stack such that the largest elements are on top
            while (!st.empty() && st.top() <= ele) {
                st.pop();
            }

            // If stack is empty, no greater element exists; otherwise, the top is the next greater element
            int res = (st.empty()) ? -1 : st.top();
            umap[ele] = res;
            st.push(ele);
        }

        // Create the result vector based on nums1
        vector<int> ans;
        for (auto x : nums1) {
            ans.push_back(umap[x]);
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    // Get the next greater elements
    vector<int> result = solution.nextGreaterElement(nums1, nums2);

    // Output the result
    cout << "Next greater elements for nums1 based on nums2: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
