#include <iostream>
#include <map>

struct Node {
    int data;
    struct Node* next;
    
    Node(int x) : data(x), next(NULL) {}
};

// Function to detect a loop in a linked list
bool detectLoop(Node* head) {
    if(head == NULL)
        return false;

    std::map<Node*, bool> visited;
    Node* temp = head;

    while(temp != NULL) {
        if(visited[temp] == true) {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

// Helper function to print the linked list
void printList(Node *head) {
    while(head != NULL) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to append a new node at the end
void appendNode(Node* &head, int data) {
    if(head == NULL) {
        head = new Node(data);
        return;
    }
    
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

int main() {
    Node* head = NULL;
    
    // Creating a linked list: 1->2->3->4->5
    for(int i = 1; i <= 5; i++) {
        appendNode(head, i);
    }

    std::cout << "Original Linked List: ";
    printList(head);

    // Creating a loop for testing: connecting the last node to the second node
    head->next->next->next->next->next = head->next;

    if(detectLoop(head)) {
        std::cout << "Loop detected in the linked list" << std::endl;
    } else {
        std::cout << "No loop detected in the linked list" << std::endl;
    }

    return 0;
}
