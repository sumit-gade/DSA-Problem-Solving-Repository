#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

int checkMirrorTree(int n, int e, int A[], int B[]) {
    unordered_map<int, stack<int>> m;
    
    for (int i = 0; i < 2 * e; i += 2) {
        m[A[i]].push(A[i + 1]);
    }

    for (int i = 0; i < 2 * e; i += 2) {
        if (m[B[i]].top() != B[i + 1]) return 0;
        m[B[i]].pop();
    }
    
    return 1;
}

int main() {
    int n = 3; // Number of nodes
    int e = 2; // Number of edges
    int A[] = {1, 2, 1, 3}; // First tree edges
    int B[] = {1, 3, 1, 2}; // Second tree edges (should be the mirror of A)

    if (checkMirrorTree(n, e, A, B)) {
        cout << "The trees are mirror images of each other." << endl;
    } else {
        cout << "The trees are not mirror images of each other." << endl;
    }

    return 0;
}
