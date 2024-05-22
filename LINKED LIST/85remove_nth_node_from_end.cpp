#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast ahead by n steps
        while (n--) {
            fast = fast->next;
        }

        // Edge case: if fast is null, n is equal to the length of the list
        // and we need to remove the head node
        if (fast == nullptr) {
            return head->next;
        }

        // Move both pointers until fast reaches the end
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Skip the N-th node from the end
        slow->next = slow->next->next;

        return head;
    }
};

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;  // Remove the 2nd node from the end

    Solution sol;
    ListNode* result = sol.removeNthFromEnd(head, n);

    // Print the modified linked list
    printList(result);

    // Free the allocated memory (optional in this example)
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
