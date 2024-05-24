#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* Mid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeSortedList(ListNode *p1, ListNode *p2) {
        if (p1 == nullptr) return p2;
        if (p2 == nullptr) return p1;

        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                curr->next = p1;
                p1 = p1->next;
            } else {
                curr->next = p2;
                p2 = p2->next;
            }
            curr = curr->next;
        }

        if (p1 != nullptr) {
            curr->next = p1;
        } else {
            curr->next = p2;
        }

        ListNode* result = ans->next;
        delete ans;  // Delete the dummy node
        return result;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* mid = Mid(head);
        ListNode* newhead = mid->next;
        mid->next = nullptr;

        ListNode* left_half = sortList(head);
        ListNode* right_half = sortList(newhead);

        return mergeSortedList(left_half, right_half);
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int arr[] = {4, 2, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, size);

    Solution solution;
    head = solution.sortList(head);

    printList(head);  // Output should be: 1 2 3 4

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
