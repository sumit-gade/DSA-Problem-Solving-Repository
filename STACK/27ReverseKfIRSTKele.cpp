#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    queue<int> ans;
    stack<int> st;

    // Push first k elements into a stack
    for(int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Enqueue the elements from the stack to the answer queue
    while(!st.empty()) {
        ans.push(st.top());
        st.pop();
    }

    // Enqueue the remaining elements from the original queue to the answer queue
    while(!q.empty()) {
        ans.push(q.front());
        q.pop();
    }

    return ans;
}

int main() {
    // Example input
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    // Printing original queue
    cout << "Original queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Modifying the queue
    q = modifyQueue(q, k);

    // Printing modified queue
    cout << "Modified queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
