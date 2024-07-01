#include <iostream>
#include <climits>
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
    void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {
        // Base case
        if (root == NULL) {
            if (len > maxLen) {
                maxLen = len;
                maxSum = sum;
            } else if (len == maxLen) {
                maxSum = max(sum, maxSum);
            }
            return;
        }
        
        sum = sum + root->data;
        
        solve(root->left, sum, maxSum, len + 1, maxLen);
        solve(root->right, sum, maxSum, len + 1, maxLen);
    }
    
    int sumOfLongRootToLeafPath(Node *root) {
        int len = 0;
        int maxLen = 0;
        int sum = 0;
        int maxSum = INT_MIN;
        
        solve(root, sum, maxSum, len, maxLen);
        
        return maxSum;
    }
};

// Helper function to create a new node
Node* newNode(int data) {
    Node* node = new Node(data);
    return node;
}

int main() {
    // Creating a binary tree
    Node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(6);

    Solution sol;
    int result = sol.sumOfLongRootToLeafPath(root);
    cout << "The sum of the longest root to leaf path is: " << result << endl;

    return 0;
}
