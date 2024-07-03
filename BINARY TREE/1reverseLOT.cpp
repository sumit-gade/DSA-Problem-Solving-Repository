#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

vector<int> reverseLevelOrder(Node *root) {
    vector<int> ans;
    if (root == nullptr) {
        return ans;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        ans.push_back(temp->data);
        
        // Enqueue right child first, then left child
        if (temp->right != nullptr) {
            q.push(temp->right);
        }
        
        if (temp->left != nullptr) {
            q.push(temp->left);
        }
    }
    
    // Reverse the order of the elements to get reverse level order
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    vector<int> result = reverseLevelOrder(root);
    
    cout << "Reverse Level Order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    
    return 0;
}
