#include <iostream>
#include <stack>

class MinStack {
public:
    // Two stacks: one for storing all elements (st)
    // and one for storing minimum elements (s2)
    std::stack<int> st, s2;

    // Constructor for MinStack
    MinStack() {
    }

    // Push function to add element to the stack
    void push(int val) {
        // If s2 is empty or the value is less than or equal to the current minimum, push it onto s2
        if (s2.empty() || val <= s2.top()) {
            s2.push(val);
        }
        // Push the value onto the main stack st
        st.push(val);
    }

    // Pop function to remove the top element from the stack
    void pop() {
        // If the top element of st is the same as the top element of s2, pop from s2 as well
        if (st.top() == s2.top()) {
            s2.pop();
        }
        // Pop the top element from st
        st.pop();
    }

    // Top function to return the top element of the stack
    int top() {
        return st.top();
    }

    // getMin function to return the minimum element in the stack
    int getMin() {
        return s2.top();
    }
};

int main() {
    // Instantiate the MinStack object
    MinStack* obj = new MinStack();
    
    // Example usage
    obj->push(3);
    obj->push(5);
    std::cout << "Current min: " << obj->getMin() << std::endl; // Output: 3
    obj->push(2);
    obj->push(1);
    std::cout << "Current min: " << obj->getMin() << std::endl; // Output: 1
    obj->pop();
    std::cout << "Current min: " << obj->getMin() << std::endl; // Output: 2
    obj->pop();
    std::cout << "Top element: " << obj->top() << std::endl; // Output: 5
    std::cout << "Current min: " << obj->getMin() << std::endl; // Output: 3

    // Clean up
    delete obj;
    
    return 0;
}
