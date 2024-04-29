#include <iostream>
using namespace std;

// Definition of Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to insert a new node at the end of a linked list
void insertAtEnd(Node** head, int val) {
    Node* newNode = new Node(val);
    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print a linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to check if two linked lists are identical
bool areIdentical(Node* head1, Node* head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data != head2->data) {  // value check
            return false;
        }

        head1 = head1->next;  // traverse
        head2 = head2->next;
    }

    if (head1 != nullptr || head2 != nullptr) {  // check if lengths are unequal
        return false;
    }

    return true;  // If we reach here, they are identical
}

int main() {
    // Create two linked lists
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    // Insert elements into the first list
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 2);
    insertAtEnd(&list1, 3);

    // Insert elements into the second list
    insertAtEnd(&list2, 1);
    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 3);

    // Print the lists
    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    // Check if the lists are identical
    if (areIdentical(list1, list2)) {
        cout << "The linked lists are identical." << endl;
    } else {
        cout << "The linked lists are not identical." << endl;
    }

    // Modify list2 to make them not identical
    list2->next->next->data = 4;

    cout << "\nAfter modification:" << endl;
    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    // Check again if the lists are identical
    if (areIdentical(list1, list2)) {
        cout << "The linked lists are identical." << endl;
    } else {
        cout << "The linked lists are not identical." << endl;
    }

    return 0;
}
