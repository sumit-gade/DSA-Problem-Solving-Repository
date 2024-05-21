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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0); // Dummy node to simplify edge cases
        ListNode* curr = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        // Attach the remaining elements of list1 or list2
        if (list1 != nullptr) {
            curr->next = list1;
        } else if (list2 != nullptr) {
            curr->next = list2;
        }

        return dummy.next; // Return the merged list, skipping the dummy node
    }
};

int main() {
    // Create first sorted linked list: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // Create second sorted linked list: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution sol;
    ListNode* mergedList = sol.mergeTwoLists(list1, list2);

    // Print the merged linked list
    printList(mergedList);

    // Free the allocated memory (optional in this example)
    while (mergedList != nullptr) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
