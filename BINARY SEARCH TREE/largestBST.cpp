#include <iostream>
#include <climits>
using namespace std;

// Node structure definition
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    struct info {
        int maxi;
        int mini;
        bool isBST;
        int size;
    };
    
    info solve(Node* root, int &maxSize) {
        if (root == NULL)
            return {INT_MIN, INT_MAX, true, 0};
        
        info left = solve(root->left, maxSize);
        info right = solve(root->right, maxSize);
        
        info currNode;
        
        currNode.size = left.size + right.size + 1;
        currNode.maxi = max(root->data, right.maxi);
        currNode.mini = min(root->data, left.mini);
        
        if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
            currNode.isBST = true;
        } else {
            currNode.isBST = false;  // Set isBST to false if current node doesn't satisfy the BST conditions
        }
        
        if (currNode.isBST) {
            maxSize = max(maxSize, currNode.size);
        }
        
        return currNode;
    }
    
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        int maxSize = 0;
        solve(root, maxSize);
        return maxSize;
    }
};

int main() {
    // Creating the example binary tree:
    //         10
    //        /  \
    //       5    15
    //      / \     \
    //     1   8    20
    
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(20);
    
    Solution sol;
    int largestBSTSize = sol.largestBst(root);
    cout << "The size of the largest BST subtree is: " << largestBSTSize << endl;
    
    return 0;
}
