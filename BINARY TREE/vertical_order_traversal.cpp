#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

vector<int> verticalOrder(Node* root) {
    map<int, vector<int>> m;  // Horizontal distance and corresponding nodes
    queue<pair<Node*, int>> q;  // Nodes and their horizontal distance

    vector<int> ans;

    if (root == NULL)
        return ans;

    q.push({root, 0}); // First element of the binary tree with horizontal distance 0

    while (!q.empty()) {
        Node* temp = q.front().first; // Current node
        int z = q.front().second;  // Current horizontal distance
        q.pop();

        m[z].push_back(temp->data); // Map the node's data to its horizontal distance

        if (temp->left != NULL) {
            q.push({temp->left, z - 1}); // Decrease horizontal distance for the left child
        }

        if (temp->right != NULL) {
            q.push({temp->right, z + 1}); // Increase horizontal distance for the right child
        }
    }

    for (const auto& i : m) { // Iterate over the map
        for (const auto& ele : i.second) {
            ans.push_back(ele); // Push the nodes into the answer vector
        }
    }

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

    vector<int> result = verticalOrder(root);

    cout << "Vertical order traversal: ";
    for (int val : result) {
        cout << val << " ";
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
