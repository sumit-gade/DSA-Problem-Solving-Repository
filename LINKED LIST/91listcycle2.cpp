#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to print the linked list (prints up to a certain number of nodes to prevent infinite loop in case of a cycle)
void printList(ListNode* head, int maxNodes = 20) {
    int count = 0;
    while (head != nullptr && count < maxNodes) {
        cout << head->val << " ";
        head = head->next;
        count++;
    }
    cout << endl;
}

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

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // Cycle detected
                while (entry != slow) { // Find the entry point of the cycle
                    slow = slow->next;
                    entry = entry->next;
                }
                return slow; // Entry point of the cycle
            }
        }
        return nullptr; // No cycle
    }
};

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
    ListNode* cycleNode = sol.detectCycle(head);

    if (cycleNode) {
        cout << "Cycle detected at node with value: " << cycleNode->val << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    // To prevent memory leaks in non-cyclic part (optional)
    // In a real-world scenario, you'd ensure to properly handle cyclic linked lists.
    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
        if (head == cycleNode) break; // Prevent infinite loop in case of cycle
    }

    return 0;
}
