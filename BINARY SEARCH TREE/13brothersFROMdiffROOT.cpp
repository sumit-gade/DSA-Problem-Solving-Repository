#include <iostream>
#include <unordered_set>
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

// Inorder traversal to fill an unordered set
void inorder(Node* root, unordered_set<int>& s) {
    if (!root) return;
    inorder(root->left, s);
    s.insert(root->data);
    inorder(root->right, s);
}

// Function to count pairs that sum up to 'x'
int countPairs(Node* root1, Node* root2, int x) {
    unordered_set<int> b1, b2;
    
    // Inorder traversal to populate sets with elements of the trees
    inorder(root1, b1);
    inorder(root2, b2);
    
    int ans = 0;
    
    // Check if pair (it, x - it) exists
    for (auto it : b1) {
        if (b2.find(x - it) != b2.end()) {
            ans++;
        }
    }
    
    return ans;
}

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node(data);
    return temp;
}

int main() {
    // Create first BST
    Node* root1 = newNode(5);
    root1->left = newNode(3);
    root1->right = newNode(7);
    root1->left->left = newNode(2);
    root1->left->right = newNode(4);
    root1->right->left = newNode(6);
    root1->right->right = newNode(8);
    
    // Create second BST
    Node* root2 = newNode(10);
    root2->left = newNode(6);
    root2->right = newNode(15);
    root2->left->left = newNode(3);
    root2->left->right = newNode(8);
    root2->right->left = newNode(11);
    root2->right->right = newNode(18);

    // Example to find the number of pairs that sum to 16
    int x = 16;
    int result = countPairs(root1, root2, x);
    cout << "Number of pairs with sum " << x << ": " << result << endl;
    
    return 0;
}
