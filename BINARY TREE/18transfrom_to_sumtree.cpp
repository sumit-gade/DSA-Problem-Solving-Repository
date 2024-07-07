#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to convert a tree to a sum tree
int solve(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int a = solve(root->left);
    int b = solve(root->right);
    int x = root->data;
    root->data = a + b;
    return a + b + x;
}

// Function to initiate the conversion to a sum tree
void toSumTree(Node *node) {
    solve(node);
}

// Function to print the tree in order
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Creating an example tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(18);

    cout << "Original tree (inorder): ";
    inorder(root);
    cout << endl;

    // Converting to sum tree
    toSumTree(root);

    cout << "Sum tree (inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
