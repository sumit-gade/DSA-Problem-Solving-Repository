#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse the linked list
struct Node* reverseList(struct Node *head) {
    struct Node* cur = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    while (cur != NULL) {
        next = cur->next;  // Save the next node
        cur->next = prev;  // Reverse the current node's pointer
        prev = cur;        // Move the previous pointer one step forward
        cur = next;        // Move to the next node
    }
    head = prev;           // Reset head to the new front of the list
    return head;
}

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a linked list 1->2->3->4->5->NULL
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Original List: ");
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}
