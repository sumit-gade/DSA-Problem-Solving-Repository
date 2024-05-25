#include <iostream>

struct node {
    int data;
    struct node* next;
    
    node(int x) : data(x), next(NULL) {}
};

// Function to reverse the linked list in groups of size k
struct node *reverseIt(struct node *head, int k) { 
    if(head == NULL) {
        return NULL;
    }
    
    node* next = NULL;
    node* curr = head;
    node* prev = NULL;
    int count = 0;
    
    // Reverse the first k nodes of the linked list
    while(curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    // Now next points to (k+1)th node
    // Recursively call for the list starting from current.
    // And make rest of the list as next of first node
    if(next != NULL) {
        head->next = reverseIt(next, k);
    }
    
    // prev is now head of the input list
    return prev;
}

// Helper function to print the linked list
void printList(node *head) {
    while(head != NULL) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to append a new node at the end
void appendNode(node* &head, int data) {
    if(head == NULL) {
        head = new node(data);
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new node(data);
}

int main() {
    node* head = NULL;
    
    // Creating a linked list: 1->2->3->4->5->6->7->8->9
    for(int i = 1; i <= 9; i++) {
        appendNode(head, i);
    }
    
    std::cout << "Original Linked List: ";
    printList(head);
    
    int k = 3;
    head = reverseIt(head, k);
    
    std::cout << "Reversed Linked List in groups of " << k << ": ";
    printList(head);
    
    return 0;
}
