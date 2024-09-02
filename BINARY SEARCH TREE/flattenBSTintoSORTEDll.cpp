#include <iostream>
using namespace std;

// Definition of Node for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Inorder traversal to flatten the BST
void inorder(Node* curr, Node*& prev) {
    if (curr == NULL)
        return;

    inorder(curr->left, prev);

    prev->left = NULL;  // Flatten the tree by nullifying the left child
    prev->right = curr; // Right child of prev becomes current node
    prev = curr;        // Move prev to current node

    inorder(curr->right, prev);
}

// Function to flatten the BST into a sorted linked list
Node* flattenBST(Node* root) {
    Node* dummy = new Node(-1); // Temporary dummy node
    Node* prev = dummy;
    
    inorder(root, prev);

    prev->left = NULL;
    prev->right = NULL;

    Node* ans = dummy->right; // Head of the flattened linked list
    delete dummy; // Clean up the dummy node
    
    return ans;
}

int main() {
    // Example usage
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(30);

    Node* flattenedList = flattenBST(root);

    // Print the flattened list
    Node* curr = flattenedList;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->right;
    }

    return 0;
}
