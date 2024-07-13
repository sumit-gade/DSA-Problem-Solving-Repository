#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int countLeaves(Node* root) {
    // If the tree is empty, return 0
    if (!root)
        return 0;
    
    // Initialize a queue for BFS
    queue<Node*> q;
    int count = 0; // Count of leaf nodes
    q.push(root);
    
    // Perform BFS
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        // If left child exists, push it to the queue
        if (temp->left != NULL) {
            q.push(temp->left);
        }
        
        // If right child exists, push it to the queue
        if (temp->right != NULL) {
            q.push(temp->right);
        }
        
        // If the current node is a leaf, increment the count
        if (temp->left == NULL && temp->right == NULL) {
            count++;
        }
    }
    
    return count;
}

int main() {
    // Example tree:
    //      1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   6
    //         /
    //        7

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    cout << "Number of leaf nodes: " << countLeaves(root) << endl;

    return 0;
}
