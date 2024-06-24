#include <iostream>
#include <vector>
using namespace std;

// Define the structure for a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function for in-order traversal
void inOrderHelper(Node* root, vector<int>& result) {
    if (root == NULL) return;
    
    inOrderHelper(root->left, result);
    result.push_back(root->data);
    inOrderHelper(root->right, result);
}

// Function to return the in-order traversal as a vector
vector<int> inOrder(Node* root) {
    vector<int> result;
    inOrderHelper(root, result);
    return result;
}

int main() {
    // Create the binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Get the in-order traversal
    vector<int> result = inOrder(root);

    // Print the in-order traversal
    cout << "In-order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
