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
    int size(ListNode* head) {
        int n = 0;
        while (head != nullptr) {
            n++;
            head = head->next;
        }
        return n;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        
        int n = size(head);
        int loop = k % n;
        loop = n - loop;
        
        if (n == 1 || loop == n) return head;
        
        int j = 0;
        ListNode* temp = head;
        ListNode* firstAddress = head;
        
        while (temp != nullptr) {
            j++;
            if (j == loop) {
                firstAddress = temp->next;
                temp->next = nullptr;
                break;
            }
            temp = temp->next;
        }
        
        temp = firstAddress;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        temp->next = head;
        return firstAddress;
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
    
    int k = 2;
    ListNode* rotatedHead = solution.rotateRight(head, k);
    
    cout << "Rotated list by " << k << ": ";
    printList(rotatedHead);
    
    return 0;
}
