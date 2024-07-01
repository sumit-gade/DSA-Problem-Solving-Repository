#include <iostream>
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
    Node* lca(Node* root, int n1, int n2)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data == n1 || root->data == n2)
        {
            return root;
        }
        
        Node* leftAns = lca(root->left, n1, n2);
        Node* rightAns = lca(root->right, n1, n2);
        
        if (leftAns != NULL && rightAns != NULL)
        {
            return root;
        }
        else if (leftAns != NULL && rightAns == NULL)
        {
            return leftAns;
        }
        else if (leftAns == NULL && rightAns != NULL)
        {
            return rightAns;
        }
        else
        {
            return NULL;
        }
    }
};

// Helper function to create a new node
Node* newNode(int data)
{
    Node* node = new Node(data);
    return node;
}

int main()
{
    // Creating a binary tree
    Node *root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);

    Solution sol;
    int n1 = 5, n2 = 1;
    Node* lcaNode = sol.lca(root, n1, n2);
    if (lcaNode != NULL)
    {
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lcaNode->data << endl;
    }
    else
    {
        cout << "LCA does not exist for " << n1 << " and " << n2 << endl;
    }

    return 0;
}
