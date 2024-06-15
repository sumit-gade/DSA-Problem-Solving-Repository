#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeQueue(queue<int> &q) {
    stack<int> s;
    int n = q.size();
    vector<int> result;

    // Step 1: Push the first half of the queue into the stack
    for (int i = 0; i < n / 2; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue the elements from the stack back to the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move the first half of the queue to the back
    for (int i = 0; i < n / 2; i++) {
        q.push(q.front());
        q.pop();
    }

    // Step 4: Push the first half of the queue into the stack again
    for (int i = 0; i < n / 2; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 5: Interleave the elements from the stack and the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }

    // Collect the elements in the queue into a result vector
    while (!q.empty()) {
        result.push_back(q.front());
        q.pop();
    }

    return result;
}

int main() {
    // Example input
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    // Printing original queue
    cout << "Original queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Rearranging the queue
    vector<int> result = rearrangeQueue(q);

    // Printing rearranged queue
    cout << "Rearranged queue: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
