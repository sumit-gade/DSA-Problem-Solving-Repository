#include <iostream>
#include <climits>
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

// Function to check if a binary tree is a valid BST
bool validBST(Node* root, int min, int max) {
    if (root == NULL) {
        return true;
    }
    
    if (root->data > min && root->data < max) {
        bool left = validBST(root->left, min, root->data);
        bool right = validBST(root->right, root->data, max);
        return left && right;
    } else {
        return false;
    }
}

// Wrapper function to check if a binary tree is a BST
bool isBST(Node* root) {
    return validBST(root, INT_MIN, INT_MAX);
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

// Inorder traversal (left, root, right)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;

    if (isBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is not a valid BST." << endl;
    }

    return 0;
}
