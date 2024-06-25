#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to check if two trees are identical.
bool isIdentical(Node* r1, Node* r2) {
    if (r1 == NULL && r2 == NULL) {
        return true;
    }
    
    if ((r1 != NULL && r2 == NULL) || (r1 == NULL && r2 != NULL)) {
        return false;
    }
    
    if (r1->data == r2->data) {
        return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    } else {
        return false;
    }
}

int main() {
    // Creating the first sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->right = new Node(6);

    // Creating the second sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->right = new Node(6);

    // Check if the two trees are identical
    bool identical = isIdentical(root1, root2);

    // Print the result
    if (identical) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }

    // Clean up memory
    delete root1->left->left;
    delete root1->left->right;
    delete root1->right->right;
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left->left;
    delete root2->left->right;
    delete root2->right->right;
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}
