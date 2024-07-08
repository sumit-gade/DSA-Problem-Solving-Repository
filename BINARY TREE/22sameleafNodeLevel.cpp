#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Global variable to store the result
int ans;

// Recursive function to check leaf levels
void solve(Node* root, int height, int &level) {
    if (root == NULL) return;

    if (ans == 0) return;

    if (!root->left && !root->right) { // if it's a leaf node
        if (level == -1) { // first leaf level
            level = height; // fix the level at first leaf
        } else { // other leaf nodes
            if (height != level) {
                ans = 0;
            }
        }
        return;
    }
    // if it's not a leaf node
    solve(root->left, height + 1, level); 
    solve(root->right, height + 1, level);
}

// Function to check if all leaf nodes are at the same level
bool check(Node *root) {
    int level = -1;
    int height = 0;
    ans = 1; // initialize the global variable ans
    solve(root, height, level);
    return ans;
}

// Function to build the tree for testing
Node* buildTree(string str) {   
    if (str.length() == 0 || str[0] == 'N') return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str; ) ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

int main() {
    // Example test cases
    vector<string> testCases = {
        "1 2 3 4 5 N N N N 6 7",
        "10 20 30 40 50 N N",
        "1 2 3 N N 4 5"
    };

    for (string testCase : testCases) {
        Node* root = buildTree(testCase);
        cout << (check(root) ? "1" : "0") << endl;
    }

    return 0;
}
