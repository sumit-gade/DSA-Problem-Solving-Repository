#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

vector<int> levelOrder(Node* root) {
    vector<int> ans;
    queue<Node*> q;
    
    if (root == NULL) {
        return ans;
    }
    
    q.push(root);
    
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        ans.push_back(temp->data);
        
        if (temp->left != NULL) {
            q.push(temp->left);
        }
        
        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
    
    return ans;
}

// Helper function to insert nodes in the tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 6);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 8);
    root = insertNode(root, 12);
    root = insertNode(root, 17);
    
    vector<int> result = levelOrder(root);
    
    for (int val : result) {
        cout << val << " ";
    }
    
    return 0;
}
