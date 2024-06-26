#include <iostream>
#include <cmath> // for abs function
using namespace std;

// Structure of the node of the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    int f; // flag to indicate if the tree is balanced

    // Helper function to check the height of the tree and determine if it is balanced
    int solve(Node* root) {
        if (!root) return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        if (abs(l - r) > 1) f = 0;

        return max(l, r) + 1;
    }

    // Function to check whether a binary tree is balanced or not
    bool isBalanced(Node* root) {
        f = 1;
        solve(root);
        return f;
    }
};

// Helper function to insert nodes in the tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int main() {
    Node* root = NULL;
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
