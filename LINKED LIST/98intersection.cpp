#include <iostream>
#include<vector>
#include <cmath> // For abs()

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr = headA;
        int a = 0, b = 0;

        // Calculate the length of list A
        while (curr) {
            a++;
            curr = curr->next;
        }

        // Calculate the length of list B
        curr = headB;
        while (curr) {
            b++;
            curr = curr->next;
        }

        // Find the difference in lengths
        int diff = abs(a - b);

        // Adjust the starting point for the longer list
        if (a < b) {
            while (diff--) {
                headB = headB->next;
            }
        } else {
            while (diff--) {
                headA = headA->next;
            }
        }

        // Traverse both lists together to find the intersection
        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create a linked list from a vector and return the head
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return NULL;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to get the tail node of a linked list
ListNode* getTail(ListNode* head) {
    while (head && head->next) {
        head = head->next;
    }
    return head;
}

// Main function to test the solution
int main() {
    // Create two linked lists
    vector<int> valsA = {4, 1};
    vector<int> valsB = {5, 6, 1};
    vector<int> valsC = {8, 4, 5}; // Intersection part

    ListNode* headA = createList(valsA);
    ListNode* headB = createList(valsB);
    ListNode* headC = createList(valsC);

    // Connect the lists to make an intersection
    ListNode* tailA = getTail(headA);
    ListNode* tailB = getTail(headB);
    tailA->next = headC;
    tailB->next = headC;

    // Print the lists
    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    // Find the intersection
    Solution solution;
    ListNode* intersection = solution.getIntersectionNode(headA, headB);

    if (intersection) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection found" << endl;
    }

    return 0;
}
