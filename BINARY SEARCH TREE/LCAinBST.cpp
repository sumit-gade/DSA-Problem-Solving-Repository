#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Function to find the Lowest Common Ancestor (LCA) of two nodes in a BST
Node* LCA(Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }

    // If both n1 and n2 are greater than root, LCA lies in the right subtree
    if (root->data < n1 && root->data < n2) {
        return LCA(root->right, n1, n2);
    }

    // If both n1 and n2 are smaller than root, LCA lies in the left subtree
    if (root->data > n1 && root->data > n2) {
        return LCA(root->left, n1, n2);
    }

    // If one key is greater and the other is smaller, the current node is the LCA
    return root;
}

// Function to insert nodes into the BST
Node* insert(Node* node, int data) {
    if (node == NULL) {
        return new Node(data);
    }

    if (data > node->data) {
        node->right = insert(node->right, data);
    } else if (data < node->data) {
        node->left = insert(node->left, data);
    }

    return node;
}

int main() {
    Node* root = NULL;
    root = insert(root, 20);
    insert(root, 8);
    insert(root, 22);
    insert(root, 4);
    insert(root, 12);
    insert(root, 10);
    insert(root, 14);

    int n1 = 10, n2 = 14;
    Node* lca = LCA(root, n1, n2);
    if (lca != NULL) {
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    } else {
        cout << "LCA does not exist in the BST." << endl;
    }

    return 0;
}
