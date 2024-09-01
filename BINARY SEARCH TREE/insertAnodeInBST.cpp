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

    return 0;
}
