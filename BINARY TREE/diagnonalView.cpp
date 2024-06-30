#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to get the diagonal traversal of the binary tree.
vector<int> diagonal(Node* root) {
    queue<Node*> q;
    vector<int> ans;

    if (root == NULL)
        return ans;

    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        while (temp) {
            if (temp->left)
                q.push(temp->left); // Add the left child to the queue
            ans.push_back(temp->data);
            temp = temp->right; // Move to the right child
        }
    }
    return ans;
}

// Helper function to print the elements of the vector.
void printDiagonal(const vector<int>& ans) {
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;
}

// Main function to test the diagonal function.
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

    vector<int> diagonal_view = diagonal(root);
    cout << "Diagonal traversal of the binary tree is: ";
    printDiagonal(diagonal_view);

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
