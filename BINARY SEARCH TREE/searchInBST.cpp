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

// Function to search a value in the BST
bool search(Node* root, int x) {
    if (root == nullptr) {
        return false;
    }
    
    if (root->data == x) {
        return true;
    }
    
    if (x > root->data) {
        return search(root->right, x);
    } else {
        return search(root->left, x);
    }
}

// Main function to demonstrate the search operation
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

    // Search for values in the BST
    int searchValue1 = 7;
    int searchValue2 = 17;
    
    if (search(root, searchValue1)) {
        cout << searchValue1 << " found in the BST." << endl;
    } else {
        cout << searchValue1 << " not found in the BST." << endl;
    }
    
    if (search(root, searchValue2)) {
        cout << searchValue2 << " found in the BST." << endl;
    } else {
        cout << searchValue2 << " not found in the BST." << endl;
    }

    return 0;
}
