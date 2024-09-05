#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* next;  // Pointer to the in-order successor
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
        next = NULL;  // Initialize 'next' as NULL
    }
};

// Function to populate the 'next' pointer
void solve(Node* root, Node* &prev) {
    if (!root) return;
    
    // Recursively go to the left subtree
    solve(root->left, prev);
    
    // Set the 'next' of the previous node to the current node
    if (prev != NULL) {
        prev->next = root;
    }
    
    // Update the previous node to the current node
    prev = root;
    
    // Recursively go to the right subtree
    solve(root->right, prev);
}

void populateNext(Node *root) {
    Node* prev = NULL;
    solve(root, prev);
}

// Function to print the in-order traversal along with 'next' pointers
void printInOrderWithNext(Node* root) {
    Node* current = root;
    
    // Find the leftmost node (start of in-order traversal)
    while (current && current->left) {
        current = current->left;
    }
    
    // Print each node's data and its 'next' pointer
    while (current) {
        cout << "Node " << current->data << " -> ";
        if (current->next) {
            cout << "Next: " << current->next->data << endl;
        } else {
            cout << "Next: NULL" << endl;
        }
        current = current->next;
    }
}

int main() {
    // Creating the example BST:
    //         10
    //        /  \
    //       5    15
    //      / \     \
    //     2   8    20
    
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(8);
    root->right->right = new Node(20);
    
    // Populating the 'next' pointers
    populateNext(root);
    
    // Printing the in-order traversal with 'next' pointers
    cout << "In-order traversal with 'next' pointers:" << endl;
    printInOrderWithNext(root);
    
    return 0;
}
