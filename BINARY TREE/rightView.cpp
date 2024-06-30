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

// Function to get the right view of the binary tree.
void right(Node* root, int level, vector<int>& ans) {
    if (root == NULL) return;

    if (ans.size() == level) ans.push_back(root->data); // we entered into new level
    right(root->right, level + 1, ans);
    right(root->left, level + 1, ans);
}

// Function to return a list containing elements of the right view of the binary tree.
vector<int> rightView(Node* root) {
    vector<int> ans;
    right(root, 0, ans);
    return ans;
}

// Helper function to print the elements of the vector.
void printRightView(const vector<int>& ans) {
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;
}

// Main function to test the right view function.
int main() {
    // Creating a sample binary tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> right_view = rightView(root);
    cout << "Right view of the binary tree is: ";
    printRightView(right_view);

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
