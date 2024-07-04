#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to mirror the binary tree
void mirror(Node* node) {
    if (node == NULL) {
        return;
    }

    // Recursively mirror the left and right subtrees
    mirror(node->left);
    mirror(node->right);

    // Swap the left and right pointers
    swap(node->left, node->right);
}

// Function to print in-order traversal of the binary tree
void inorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }

    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

// Sample usage
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "In-order traversal of the original tree: ";
    inorderTraversal(root);
    cout << endl;

    // Mirror the binary tree
    mirror(root);

    cout << "In-order traversal of the mirrored tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
