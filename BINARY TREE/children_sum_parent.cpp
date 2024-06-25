#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to check if the binary tree satisfies the children sum property.
int isSumProperty(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 1;
    }
    
    int left_sum = 0, right_sum = 0;
    
    if (root->left != NULL) {
        left_sum = root->left->data;
    }
    
    if (root->right != NULL) {
        right_sum = root->right->data;
    }
    
    if (root->data == (left_sum + right_sum) &&
        isSumProperty(root->left) &&
        isSumProperty(root->right)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Creating a sample binary tree:
    //       10
    //      /  \
    //     8    2
    //    / \    \
    //   3   5    2
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(2);

    // Check if the tree satisfies the children sum property
    bool isSum = isSumProperty(root);

    // Print the result
    if (isSum) {
        cout << "The tree satisfies the children sum property." << endl;
    } else {
        cout << "The tree does not satisfy the children sum property." << endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
