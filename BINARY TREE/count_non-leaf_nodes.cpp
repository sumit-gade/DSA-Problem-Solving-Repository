#include <iostream>
#include <queue>
using namespace std;

// Define the structure for a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to count non-leaf nodes in a binary tree
int countNonLeafNodes(Node* root) {
    if (root == nullptr) return 0; // If the tree is empty, return 0

    queue<Node*> q;
    int count = 0;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        // Check if the current node is a non-leaf node
        if (curr->left || curr->right) {
            count++;
        }
        
        // Add left and right children to the queue
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    
    return count;
}

// Function to create an example tree and test the countNonLeafNodes function
int main() {
    // Creating a sample binary tree:
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   6
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // Count non-leaf nodes
    int nonLeafNodeCount = countNonLeafNodes(root);
    cout << "Number of non-leaf nodes: " << nonLeafNodeCount << endl;

    // Clean up memory (optional for this small example)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
