#include <iostream>
using namespace std;

// Node structure definition
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a node in the BST
Node* insert(Node* node, int data) {
    if (!node) {
        return new Node(data);
    }
    
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    
    return node;
}

// Function to find the minimum value in a BST
int minValue(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

// Main function to demonstrate the minValue operation
int main() {
    Node* root = nullptr;
    
    // Insert values into the BST
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 30);
    
    // Find and print the minimum value in the BST
    int minValueInBST = minValue(root);
    cout << "Minimum value in the BST is: " << minValueInBST << endl;

    return 0;
}
