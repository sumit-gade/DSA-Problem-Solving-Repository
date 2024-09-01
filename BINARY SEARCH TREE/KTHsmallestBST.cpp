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

// Function to find the Kth smallest element in a BST
Node* kthSmallest(Node* root, int& K, int& count) {
    if (root == nullptr)
        return nullptr;

    // Inorder traversal: Left, Root, Right
    Node* left = kthSmallest(root->left, K, count); // Traverse left subtree

    if (left != nullptr)
        return left;

    count++;
    if (count == K)
        return root;

    return kthSmallest(root->right, K, count); // Traverse right subtree
}

// Wrapper function to return the Kth smallest element
int KthSmallestElement(Node* root, int K) {
    int count = 0;
    Node* result = kthSmallest(root, K, count);

    // If the Kth smallest element exists, return its data
    if (result != nullptr)
        return result->data;

    // If K is out of bounds, return -1 or another error indicator
    return -1;
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

    int K = 3; // Example: Find the 3rd smallest element
    int kthSmallestValue = KthSmallestElement(root, K);
    if (kthSmallestValue != -1) {
        cout << "The " << K << "rd smallest element in the BST is: " << kthSmallestValue << endl;
    } else {
        cout << "The " << K << "rd smallest element does not exist in the BST." << endl;
    }

    return 0;
}
