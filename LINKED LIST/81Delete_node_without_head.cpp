#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the value of the next node to the current node
        ListNode* curr = node->next;
        node->val = curr->val;
        // Link the current node to the node after the next node
        node->next = curr->next;
        // Delete the next node
        delete curr;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Create a linked list: 4 -> 5 -> 1 -> 9
    int arr[] = {4, 5, 1, 9};
    ListNode* head = createList(arr, 4);

    std::cout << "Original list: ";
    printList(head);

    // Suppose we want to delete the node with value 5 (second node)
    ListNode* nodeToDelete = head->next;

    Solution solution;
    solution.deleteNode(nodeToDelete);

    std::cout << "List after deleting node with value 5: ";
    printList(head);

    return 0;
}
