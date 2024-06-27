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

// Function to traverse the left boundary of the tree.
void traverseLeft(Node* root, vector<int>& ans) {
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return; // Exclude leaf nodes
    
    ans.push_back(root->data);
    
    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

// Function to traverse the leaf nodes of the tree.
void traverseLeaf(Node* root, vector<int>& ans) {
    if (root == NULL)
        return;
    
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }
    
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

// Function to traverse the right boundary of the tree.
void traverseRight(Node* root, vector<int>& ans) {
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return; // Exclude leaf nodes
    
    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);
    
    ans.push_back(root->data); // Reverse order
}

// Function to return a list containing elements of boundary traversal of the binary tree.
vector<int> boundary(Node* root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }
    
    ans.push_back(root->data);
    
    // Printing left boundary
    traverseLeft(root->left, ans);
    
    // Printing leaf nodes
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
    
    // Printing right boundary
    traverseRight(root->right, ans);
    
    return ans;
}

// Helper function to print the boundary traversal.
void printBoundary(vector<int> ans) {
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

// Example to create a binary tree and print its boundary traversal.
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
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    // Getting the boundary traversal of the tree
    vector<int> ans = boundary(root);

    // Printing the boundary traversal
    printBoundary(ans);

    return 0;
}
/*           1
          /      \
         2         3
       /  \      /   \
      4    5     6     7
    / \   / \   / \    / \
   8   9 10 11 12 13  14 15

*/