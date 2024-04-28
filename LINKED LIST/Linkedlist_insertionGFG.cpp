#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to insert a node at the beginning of the linked list.
Node* insertAtBegining(Node* head, int x) {
    // Creating a new node with data x
    Node* newNode = new Node(x);

    // Pointing the new node's next to the current head
    newNode->next = head;

    // Updating head to the new node
    head = newNode;

    // Returning the updated head of the list
    return head;
}

// Function to insert a node at the end of the linked list.
Node* insertAtEnd(Node* head, int x) {
    // Creating a new node with data x
    Node* newNode = new Node(x);

    // If the list is empty, the new node becomes the head
    if (head == nullptr) {
        return newNode;
    }

    // Traverse to the end of the list
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    // Link the last node to the new node
    current->next = newNode;

    // Return the head of the list (unchanged unless the list was empty)
    return head;
}

// Utility function to print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    // Test inserting at the beginning
    head = insertAtBegining(head, 10);
    head = insertAtBegining(head, 20);
    printList(head);  // Should print: 20 -> 10 -> NULL

    // Test inserting at the end
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    printList(head);  // Should print: 20 -> 10 -> 30 -> 40 -> NULL

    return 0;
}
