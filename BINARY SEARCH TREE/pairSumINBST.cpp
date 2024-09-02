#include <iostream>
#include <vector>
using namespace std;

// Definition of Node for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Inorder traversal to get sorted elements in the BST
void inorder(Node* root, vector<int> &in) {
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

// Function to check if there exists a pair with a given sum in the BST
int isPairPresent(Node *root, int target) {
    vector<int> inorderVal;
    inorder(root, inorderVal);

    int i = 0, j = inorderVal.size() - 1;

    while (i < j) {
        int sum = inorderVal[i] + inorderVal[j];

        if (sum == target)
            return true;

        else if (sum > target)
            j--;

        else
            i++;
    }
    return false;
}

int main() {
    // Example usage
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(30);

    int target = 17;

    if (isPairPresent(root, target)) {
        cout << "Pair with sum " << target << " is found in the BST." << endl;
    } else {
        cout << "No pair with sum " << target << " is found in the BST." << endl;
    }

    return 0;
}
