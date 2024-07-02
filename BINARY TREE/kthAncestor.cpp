#include <iostream>
#include <climits>

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* solve(Node* root, int &k, int node)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == node)
    {
        return root;
    }

    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }

        return leftAns;
    }
    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }

        return rightAns;
    }

    return NULL;
}

// Your task is to complete this function
int kthAncestor(Node* root, int k, int node)
{
    Node* ans = solve(root, k, node);
    if (ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}

// Function to insert nodes in level order
Node* insertLevelOrder(int arr[], Node* root, int i, int n)
{
    if (i < n)
    {
        Node* temp = new Node(arr[i]);
        root = temp;

        // Insert left child
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        // Insert right child
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = insertLevelOrder(arr, root, 0, n);

    int k = 2;
    int node = 5;

    int ancestor = kthAncestor(root, k, node);
    std::cout << "The " << k << "th ancestor of node " << node << " is: " << ancestor << std::endl;

    return 0;
}
