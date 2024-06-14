#include <bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int> q) {
    stack<int> st;
    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }
    
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    return q;
}

int main() {
    // Example input
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // Printing original queue
    cout << "Original queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Reversing the queue
    q = rev(q);

    // Printing reversed queue
    cout << "Reversed queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
