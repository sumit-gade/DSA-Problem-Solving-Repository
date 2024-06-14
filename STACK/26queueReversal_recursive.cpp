#include <bits/stdc++.h>
using namespace std;

// Recursive function to reverse the queue
void reverse(queue<int>& q) {
    if (q.empty()) {
        return;
    }
    
    int ele = q.front();
    q.pop();
    reverse(q);
    q.push(ele);
}

// Function to reverse the queue and return it
queue<int> rev(queue<int> q) {
    reverse(q);
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
