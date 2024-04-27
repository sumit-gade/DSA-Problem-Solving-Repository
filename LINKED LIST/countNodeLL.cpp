#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to count the number of nodes in a linked list
int getCount(struct Node* head) {
    struct Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;           // Increment the counter
        temp = temp->next; // Move to the next node
    }

    return count;           // Return the final count
}

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a linked list 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Original List: ");
    printList(head);

    // Get the count of nodes in the list
    int count = getCount(head);

    printf("Number of nodes in the list: %d\n", count);

    return 0;
}
