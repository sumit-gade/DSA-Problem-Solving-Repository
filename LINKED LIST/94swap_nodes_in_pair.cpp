#include <iostream>
#include<vector>
using namespace std;

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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* curr = head->next->next;
        ListNode* prev = head;
        head = head->next;
        head->next = prev;

        while (curr != nullptr && curr->next != nullptr) {
            prev->next = curr->next;
            prev = curr;
            ListNode* temp = curr->next->next;
            curr->next->next = curr;
            curr = temp;
        }

        prev->next = curr;  // For handling the odd number of nodes
        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    Solution solution;

    // Example usage
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = createList(arr);

    cout << "Original list: ";
    printList(head);

    ListNode* swappedHead = solution.swapPairs(head);

    cout << "List after swapping pairs: ";
    printList(swappedHead);

    return 0;
}
