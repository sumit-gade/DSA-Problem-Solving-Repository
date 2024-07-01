#include <iostream>
#include <vector>
using namespace std;

// Structure of the node of the binary tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void solve(Node* root, int k, int &count, vector<int> &path) {
        // Base case
        if (root == NULL)
            return;
        
        // Add current node's data to the path
        path.push_back(root->data);
        
        // Recur for left and right subtrees
        solve(root->left, k, count, path);
        solve(root->right, k, count, path);
        
        // Check for k sum paths in the current path
        int sum = 0;
        for (int i = path.size() - 1; i >= 0; i--) {
            sum += path[i];
            if (sum == k)
                count++;
        }
        
        // Remove current node's data from the path (backtrack)
        path.pop_back();
    }
    
    int sumK(Node *root, int k) {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};

// Helper function to create a new node
Node* newNode(int data) {
    Node* node = new Node(data);
    return node;
}

int main() {
    // Creating a binary tree
    Node *root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(-1);
    root->left->left = newNode(2);
    root->left->right = newNode(1);
    root->left->right->left = newNode(1);
    root->right->left = newNode(4);
    root->right->left->left = newNode(1);
    root->right->left->right = newNode(2);
    root->right->right = newNode(5);
    root->right->right->right = newNode(2);

    Solution sol;
    int k = 5;
    int result = sol.sumK(root, k);
    cout << "Number of paths with sum " << k << " is: " << result << endl;

    return 0;
}
