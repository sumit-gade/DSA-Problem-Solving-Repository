#include <iostream>
#include <vector>
#include <algorithm>  // For sorting the vector
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Inorder traversal to store the tree nodes in a vector
void inorder_tree(Node* root, vector<int>& v) {
    if (!root) return;
    inorder_tree(root->left, v);
    v.push_back(root->data);
    inorder_tree(root->right, v);
}

// Inorder traversal to replace the node values with sorted values
void inorder_bst(Node* root, vector<int>& v, int& i) {
    if (!root) return;
    inorder_bst(root->left, v, i);
    root->data = v[i];
    i++;
    inorder_bst(root->right, v, i);
}

// Function to convert binary tree to BST
Node* binaryTreeToBST(Node* root) {
    if (!root) return NULL;
    
    vector<int> v;
    inorder_tree(root, v);  // Step 1: Get all node values in inorder traversal
    sort(v.begin(), v.end());  // Step 2: Sort the values to make them suitable for a BST
    
    int i = 0;
    inorder_bst(root, v, i);  // Step 3: Replace node values with sorted values
    
    return root;
}

// Utility function for inorder traversal to print the tree (for testing)
void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Example usage
int main() {
    // Creating a binary tree
    Node* root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);

    cout << "Inorder traversal of original binary tree: ";
    printInorder(root);
    cout << endl;

    // Converting the binary tree to a BST
    root = binaryTreeToBST(root);

    cout << "Inorder traversal of converted BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}

