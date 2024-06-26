#include <iostream>
#include <cmath> // for abs function
#include <algorithm> // for max function
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(height(root->left), height(root->right)) + 1;
    }

    void inorder(TreeNode* root, bool &ans) {
        if (root != nullptr) {
            inorder(root->left, ans);

            int lh = height(root->left);
            int rh = height(root->right);

            if (abs(lh - rh) > 1) {
                ans = ans && false;
            }

            inorder(root->right, ans);
        }
    }

    bool isBalanced(TreeNode* root) {
        bool ans = true;
        inorder(root, ans);
        return ans;
    }
};

// Helper function to insert nodes in the tree
TreeNode* insertNode(TreeNode* root, int data) {
    if (root == nullptr) {
        return new TreeNode(data);
    }
    if (data < root->val) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int main() {
    TreeNode* root = nullptr;
    root = insertNode(root, 10);
    root = insertNode(root, 6);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 8);
    root = insertNode(root, 12);
    root = insertNode(root, 17);

    Solution sol;
    bool balanced = sol.isBalanced(root);

    if (balanced) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}
