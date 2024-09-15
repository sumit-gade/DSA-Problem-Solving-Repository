#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to count the nodes in range [l, h]
int getCount(Node *root, int l, int h)
{
    // Base case
    if(!root) return 0;
    
    // If the root's data is within the range
    if(root->data >= l && root->data <= h) {
        return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
    }
    // If root's data is less than l, go to the right subtree
    else if(root->data < l) {
        return getCount(root->right, l, h);
    }
    // If root's data is greater than h, go to the left subtree
    else {
        return getCount(root->left, l, h);
    }
}

// Helper function to insert nodes into the BST
Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    
    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 1);
    insert(root, 7);
    insert(root, 40);
    insert(root, 50);
    
    int l = 5, h = 45;
    cout << "Count of nodes in range [" << l << ", " << h << "] is: " << getCount(root, l, h) << endl;
    
    return 0;
}
