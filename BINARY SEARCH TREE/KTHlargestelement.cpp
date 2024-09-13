#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree from string input
Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str; ) ip.push_back(str);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

// Class to find Kth largest element in the BST
class Solution {
public:
    int ans;

    void solve(Node* root, int K, int& idx) {
        if (!root) return;

        // Traverse the right subtree first (larger elements)
        solve(root->right, K, idx);

        // Increment idx and check if we've found the Kth largest element
        if (K == idx) {
            ans = root->data;
            idx++;
            return;
        } else {
            idx++;
        }

        // Traverse the left subtree (smaller elements)
        solve(root->left, K, idx);
    }

    int kthLargest(Node* root, int K) {
        int idx = 1;
        ans = -1;
        solve(root, K, idx);
        return ans;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    getchar();

    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        int k;
        cin >> k;
        getchar();

        Solution ob;
        cout << ob.kthLargest(root, k) << endl;
    }

    return 0;
}
