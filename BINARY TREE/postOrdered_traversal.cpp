#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Helper function to perform postorder traversal.
void postOrderHelper(Node* root, vector<int>& result) {
    if (root == NULL) return;
    
    postOrderHelper(root->left, result);
    postOrderHelper(root->right, result);
    result.push_back(root->data);
}

// Function to return a list containing the postorder traversal of the tree.
vector<int> postOrder(Node* root) {
    vector<int> result;
    postOrderHelper(root, result);
    return result;
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

    // Perform postorder traversal
    vector<int> result = postOrder(root);

    // Print the result
    cout << "Postorder traversal of the binary tree is: ";
    for (int val : result) {
        cout << val << " ";
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
