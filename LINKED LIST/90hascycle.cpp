#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

// Function to create a cycle in the linked list for testing
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;
    ListNode* cycleNode = nullptr;
    ListNode* tail = head;
    int index = 0;
    while (tail->next != nullptr) {
        if (index == pos) {
            cycleNode = tail;
        }
        tail = tail->next;
        index++;
    }
    tail->next = cycleNode; // Create the cycle
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create a cycle: connect the 5th node back to the 2nd node (position 1)
    createCycle(head, 1);

    Solution sol;
    if (sol.hasCycle(head)) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    // Free the allocated memory (for demonstration purposes, will not free the cycle)
    // In practice, avoid memory leaks by ensuring cycles are properly managed.
    // However, detecting and breaking cycles before deallocation can be complex and is omitted here for simplicity.
    return 0;
}
