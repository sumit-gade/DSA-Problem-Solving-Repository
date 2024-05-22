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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast to the k-th node
        for (int i = 1; i < k; ++i) {
            fast = fast->next;
        }

        ListNode* first = fast;

        // Move fast to the end to find the k-th node from the end
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Swap values of the k-th node from the start and the k-th node from the end
        swap(first->val, slow->val);

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

    int k = 2;  // Swap the 2nd node from the beginning with the 2nd node from the end

    Solution sol;
    ListNode* result = sol.swapNodes(head, k);

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
