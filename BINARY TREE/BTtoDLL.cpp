#include <iostream>
using namespace std;

// Node structure for binary tree
struct Node {
    int data;
    Node *left, *right;
    
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Function to convert binary tree to doubly linked list
void solve(Node* root, Node* &head, Node* &prev, int &f) {
    if (root == NULL)
        return;

    // Recursively convert left subtree
    solve(root->left, head, prev, f);

    if (f == 0) {
        f = 1;
        head = root;
        prev = root;
    } else {
        prev->right = root;
        root->left = prev;
        prev = root;
    }

    // Recursively convert right subtree
    solve(root->right, head, prev, f);
}

// Function to convert binary tree to doubly linked list and return it
Node* bToDLL(Node *root) {
    Node* head = NULL;
    Node* prev = NULL;
    int f = 0;
    solve(root, head, prev, f);
    return head;
}

// Helper function to print the doubly linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;
}

int main() {
    // Constructing the binary tree
    Node* root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);

    // Convert binary tree to doubly linked list
    Node* head = bToDLL(root);

    // Print the doubly linked list
    printList(head);

    return 0;
}
