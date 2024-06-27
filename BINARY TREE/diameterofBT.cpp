#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int res = 0;

    // Function to calculate the height of the tree and update the diameter.
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        // Update the diameter (maximum path length)
        res = max(res, 1 + lh + rh);

        return 1 + max(lh, rh);
    }

    // Function to return the diameter of the binary tree.
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        height(root);
        // Subtract 1 to get the number of edges in the longest path
        return res - 1;
    }
};

// Example to create a binary tree and print its diameter.
int main() {
    Solution sol;

    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);

    // Getting the diameter of the tree
    int diameter = sol.diameterOfBinaryTree(root);

    // Printing the diameter
    cout << "Diameter of the tree: " << diameter << endl;

    return 0;
}
