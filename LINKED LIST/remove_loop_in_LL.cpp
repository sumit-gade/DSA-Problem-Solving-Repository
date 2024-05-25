#include <iostream>
#include <map>

struct Node {
    int data;
    struct Node* next;
    
    Node(int x) : data(x), next(NULL) {}
};

// Function to detect and remove a loop in a linked list
void removeLoop(Node* head) {
    if (head == NULL || head->next == NULL)
        return;
    
    Node* slow = head;
    Node* fast = head;

    // Detect loop using Floyd’s cycle-finding algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet at some point, then there is a loop
        if (slow == fast)
            break;
    }

    // If loop exists
    if (slow == fast) {
        slow = head;

        // If the loop starts at the head node
        if (slow == fast) {
            while (fast->next != slow) {
                fast = fast->next;
            }
        } else {
            // Move both pointers at the same speed to find the starting point of the loop
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Remove loop
        fast->next = NULL;
    }
}

// Function to detect a loop in a linked list
bool detectLoop(Node* head) {
    if (head == NULL)
        return false;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;
        }
    }
    
    return false;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to append a new node at the end
void appendNode(Node*& head, int data) {
    if (head == NULL) {
        head = new Node(data);
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

// Helper function to create a loop in the linked list for testing
void createLoop(Node* head, int position) {
    if (head == NULL || position == 0)
        return;

    Node* temp = head;
    Node* loopNode = NULL;
    int count = 1;

    while (temp->next != NULL) {
        if (count == position) {
            loopNode = temp;
        }
        temp = temp->next;
        count++;
    }

    if (loopNode != NULL) {
        temp->next = loopNode;
    }
}

int main() {
    int testCases;
    std::cout << "Enter number of test cases: ";
    std::cin >> testCases;

    while (testCases--) {
        Node* head = NULL;
        int n, loopPosition;
        
        std::cout << "Enter number of nodes: ";
        std::cin >> n;
        std::cout << "Enter the node values: ";
        
        for (int i = 0; i < n; i++) {
            int value;
            std::cin >> value;
            appendNode(head, value);
        }
        
        std::cout << "Enter the position to create a loop (0 for no loop): ";
        std::cin >> loopPosition;
        
        if (loopPosition > 0) {
            createLoop(head, loopPosition);
        }

        if (detectLoop(head)) {
            std::cout << "Loop detected in the linked list. Removing loop..." << std::endl;
            removeLoop(head);
            if (!detectLoop(head)) {
                std::cout << "Loop successfully removed. The linked list is now: ";
                printList(head);
            } else {
                std::cout << "Failed to remove the loop." << std::endl;
            }
        } else {
            std::cout << "No loop detected in the linked list. The linked list is: ";
            printList(head);
        }
    }

    return 0;
}
