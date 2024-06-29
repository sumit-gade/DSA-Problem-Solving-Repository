#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

vector<int> bottomView(Node* root) {
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    map<int, int> bottomNode; // HD and node  
    queue<pair<Node*, int>> q; // node and HD

    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first; // node
        int hd = temp.second; // hd

        // Always update the node data for the horizontal distance
        bottomNode[hd] = frontNode->data; // map hd to node data

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));

        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    for (auto i : bottomNode) {
        ans.push_back(i.second); // node data
    }

    return ans;
}

// Helper function to create a new node
Node* newNode(int data) {
    Node* node = new Node(data);
    node->left = node->right = NULL;
    return node;
}

int main() {
    // Creating a sample tree:
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7

    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    vector<int> result = bottomView(root);

    cout << "Bottom view of the binary tree is: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
