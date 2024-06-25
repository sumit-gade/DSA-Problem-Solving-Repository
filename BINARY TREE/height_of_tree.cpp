#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to calculate the height of a binary tree.
int height(Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        return max(height(node->left), height(node->right)) + 1;
    }
}

int main() {
    // Creating a sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // Calculate the height of the binary tree
    int treeHeight = height(root);

    // Print the result
    cout << "The height of the binary tree is: " << treeHeight << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
