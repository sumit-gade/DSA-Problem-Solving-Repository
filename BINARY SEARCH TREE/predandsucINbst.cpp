#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    
    Node(int val) : key(val), left(NULL), right(NULL) {}
};

// Function to find the inorder predecessor
Node* inpre(Node* root) {
    Node* p = root->left;
    while (p->right) {
        p = p->right;
    }
    return p;
}

// Function to find the inorder successor
Node* insuc(Node* root) {
    Node* p = root->right;
    while (p->left) {
        p = p->left;
    }
    return p;
}

// Function to find the inorder predecessor and successor
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    if (root == NULL)
        return;
    
    if (root->key == key) {
        if (root->left) 
            pre = inpre(root);
        if (root->right) 
            suc = insuc(root);
        return;
    }
    
    if (key > root->key) {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    } else if (key < root->key) {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
}

// Utility function to insert a new node in BST
Node* insert(Node* root, int key) {
    if (root == NULL) 
        return new Node(key);
    
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    
    return root;
}

// Driver code to test the findPreSuc function
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    
    int key = 65;
    Node* pre = NULL;
    Node* suc = NULL;
    
    findPreSuc(root, pre, suc, key);
    
    if (pre != NULL)
        cout << "Predecessor is " << pre->key << endl;
    else
        cout << "No Predecessor" << endl;
    
    if (suc != NULL)
        cout << "Successor is " << suc->key << endl;
    else
        cout << "No Successor" << endl;
    
    return 0;
}
