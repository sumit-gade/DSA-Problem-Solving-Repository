#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Unordered map to store subtree string representations and their frequencies
unordered_map<string, int> m;

// Helper function to serialize the subtree rooted at `root`
string solve(Node* root) {
    if (!root) return "#"; // Null nodes are represented by "#"
    
    string s = "";
    
    if (!root->left && !root->right) { // Leaf node
        s += to_string(root->data);
        s += "_";
        return s;
    }
    
    s += to_string(root->data);
    s += "_";
    s += solve(root->left);
    s += solve(root->right);
    
    m[s]++;
    
    return s;
}

// Function to detect duplicate subtrees
int dupSub(Node* root) {
    m.clear(); // Clear the map before starting
    
    solve(root);
    
    for (const auto& x : m) {
        if (x.second >= 2) return 1; // Return 1 if any subtree appears more than once
    }
    return 0; // Return 0 if no duplicate subtrees are found
}

// Helper function to create a new Node
Node* newNode(int data) {
    Node* node = new Node(data);
    return node;
}

int main() {
    /* Example Usage
           1
          / \
         2   3
        /   / \
       4   2   4
          /
         4
    */
    
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(2);
    root->right->right = newNode(4);
    root->right->left->left = newNode(4);
    
    // Check for duplicate subtrees
    if (dupSub(root)) {
        cout << "The tree has duplicate subtrees." << endl;
    } else {
        cout << "The tree does not have duplicate subtrees." << endl;
    }
    
    return 0;
}
