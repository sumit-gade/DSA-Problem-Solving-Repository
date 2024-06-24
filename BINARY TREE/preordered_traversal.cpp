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

// Helper function for pre-order traversal
void preOrderHelper(Node* root, vector<int>& result) {
    if (root == NULL) return;
    
    result.push_back(root->data);
    preOrderHelper(root->left, result);
    preOrderHelper(root->right, result);
}

// Function to return a list containing the pre-order traversal of the tree
vector<int> preorder(Node* root) {
    vector<int> result;
    preOrderHelper(root, result);
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

    // Get the pre-order traversal
    vector<int> result = preorder(root);

    // Print the pre-order traversal
    cout << "Pre-order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
