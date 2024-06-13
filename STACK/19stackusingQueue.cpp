#include <queue>
#include <iostream>

class QueueStack {
private:
    std::queue<int> q1, q2;

public:
    // Function to push an element into stack using two queues.
    void push(int x);

    // Function to pop an element from stack using two queues.
    int pop();

    // Function to check if the stack is empty.
    bool isEmpty() {
        return q2.empty();
    }
};

void QueueStack::push(int x) {
    q1.push(x);
    
    // Move all elements from q2 to q1
    while (!q2.empty()) {
        q1.push(q2.front());
        q2.pop();
    }
    
    // Swap the queues
    std::swap(q1, q2);
}

int QueueStack::pop() {
    int ans;
    if (q2.empty()) {
        ans = -1;
    } else {
        ans = q2.front();
        q2.pop();
    }
    
    return ans;
}

// Example usage
int main() {
    QueueStack stack;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << (stack.isEmpty() ? -1 : stack.pop()) << std::endl; // Should print 3
    std::cout << "Top element: " << (stack.isEmpty() ? -1 : stack.pop()) << std::endl; // Should print 2
    std::cout << "Top element: " << (stack.isEmpty() ? -1 : stack.pop()) << std::endl; // Should print 1
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl; // Should print Yes

    return 0;
}

