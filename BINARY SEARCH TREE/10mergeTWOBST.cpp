#include <iostream>
#include <vector>
using namespace std;

// Definition of a Node in a BST
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Inorder traversal to fill the vector
void inorder(Node* root, vector<int> &in) {
    if (root == NULL)
        return;
    
    inorder(root->left, in);
    in.push_back(root->data);  
    inorder(root->right, in);
}

// Merging two sorted arrays
vector<int> mergeArray(vector<int> a, vector<int> b) {
    int i = 0, j = 0;
    vector<int> ans;  // Defined the ans vector
    
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            ans.push_back(a[i]);  
            i++;
        } else {
            ans.push_back(b[j]);  
            j++;
        }
    }
    
    while (i < a.size()) {
        ans.push_back(a[i]);
        i++;
    }
    
    while (j < b.size()) {
        ans.push_back(b[j]);
        j++;
    }
    return ans;
}

// Convert sorted array to BST
Node* inorderToBST(int s, int e, vector<int> &in) {
    if (s > e)
        return NULL;
    
    int mid = (s + e) / 2;
    Node *root = new Node(in[mid]);  // Create new node from in[mid]
    
    root->left = inorderToBST(s, mid - 1, in);
    root->right = inorderToBST(mid + 1, e, in);
    
    return root;
}

// Merge two BSTs into a single sorted vector
vector<int> merge(Node *root1, Node *root2) {
    vector<int> bst1, bst2;  // Store inorder in vector
    inorder(root1, bst1);
    inorder(root2, bst2);
    
    vector<int> mergedArray = mergeArray(bst1, bst2);
    
    return mergedArray;
}

// Utility function to print inorder traversal
void printInorder(Node* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    // Create two sample BSTs
    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);
    
    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    // Merging two BSTs into a sorted vector
    vector<int> merged = merge(root1, root2);
    
    // Printing merged sorted array
    cout << "Merged Sorted Array: ";
    for (int val : merged)
        cout << val << " ";
    cout << endl;

    // Convert merged sorted array into a new BST
    Node* newRoot = inorderToBST(0, merged.size() - 1, merged);
    
    // Print inorder traversal of the new BST
    cout << "Inorder Traversal of New BST: ";
    printInorder(newRoot);
    
    return 0;
}
