#include <iostream>
#include <climits>
using namespace std;

// Definition of Node for the Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Recursive helper function to check for dead-ends
bool solve(Node* root, int min, int max) {
    if (!root) return false; // If node is NULL, return false (no dead-end)

    // If the current node is a dead-end (min == max), return true
    if (min == max) return true;

    // Recursively check in the left and right subtrees
    return solve(root->left, min, root->data - 1) || solve(root->right, root->data + 1, max);
}

// Function to check if the tree contains any dead-end
bool isDeadEnd(Node* root) {
    // Start with the minimum as 1 and maximum as INT_MAX
    return solve(root, 1, INT_MAX);
}

// Function to insert a node in BST
Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

int main() {
    // Creating a sample Binary Search Tree (BST)
    Node* root = new Node(8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 9);

    // Check for dead-end in the tree
    if (isDeadEnd(root))
        cout << "Tree contains a dead-end." << endl;
    else
        cout << "Tree does not contain a dead-end." << endl;

    return 0;
}
