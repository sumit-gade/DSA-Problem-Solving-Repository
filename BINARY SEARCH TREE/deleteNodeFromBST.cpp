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

// Function to find the minimum value in a BST (used for finding inorder successor)
Node* minValue(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int X) {
    if (root == nullptr) {
        return root;
    }
    
    if (X < root->data) {
        root->left = deleteNode(root->left, X);
    } else if (X > root->data) {
        root->right = deleteNode(root->right, X);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        Node* temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform inorder traversal of the BST
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Main function to demonstrate deleteNode operation
int main() {
    Node* root = nullptr;
    
    // Insert values into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print the inorder traversal of the original tree
    cout << "Inorder traversal of the original tree: ";
    inorder(root);
    cout << endl;

    // Delete node with value 20 (a leaf node)
    root = deleteNode(root, 20);
    cout << "Inorder traversal after deleting 20: ";
    inorder(root);
    cout << endl;

    // Delete node with value 30 (a node with one child)
    root = deleteNode(root, 30);
    cout << "Inorder traversal after deleting 30: ";
    inorder(root);
    cout << endl;

    // Delete node with value 50 (a node with two children)
    root = deleteNode(root, 50);
    cout << "Inorder traversal after deleting 50: ";
    inorder(root);
    cout << endl;

    return 0;
}
