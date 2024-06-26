#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // for std::reverse
using namespace std;

// Structure of the node of the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;
        queue<Node*> q;

        if (root == NULL)
            return ans;

        q.push(root);
        int f = 1; // flag for zigzag traversal, 1 for left to right, 0 for right to left

        while (!q.empty()) {
            vector<int> temp; // to store elements level by level
            int size = q.size();

            while (size--) {
                Node* t = q.front();
                q.pop();

                temp.push_back(t->data);

                if (t->left != NULL)
                    q.push(t->left);

                if (t->right != NULL)
                    q.push(t->right);
            }

            if (f % 2 == 0)
                reverse(temp.begin(), temp.end());

            for (int i = 0; i < temp.size(); i++)
                ans.push_back(temp[i]);

            f = !f; // toggle the flag for the next level
        }

        return ans;
    }
};

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

    Solution sol;
    vector<int> result = sol.zigZagTraversal(root);

    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
