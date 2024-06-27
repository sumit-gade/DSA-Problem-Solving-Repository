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

// Helper function to find the left view of the binary tree.
void left(Node* root, int level, vector<int>& ans) {
    if (root == NULL) return;
    
    if (ans.size() == level) ans.push_back(root->data); // we entered into new level
    left(root->left, level + 1, ans);
    left(root->right, level + 1, ans);
}

// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node* root) {
    vector<int> ans;
    left(root, 0, ans);
    return ans;
}

// Helper function to print the left view.
void printLeftView(vector<int> ans) {
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

// Example to create a binary tree and print its left view.
int main() {
    // Creating a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);

    // Getting the left view of the tree
    vector<int> ans = leftView(root);

    // Printing the left view
    printLeftView(ans);

    return 0;
}
