#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
    Node *temp = root;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Class to remove duplicates from unsorted linked list
class Solution
{
    public:
    Node * removeDuplicates(Node *head) 
    {
        unordered_set<int> seen;
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr != NULL)
        {
            if(seen.find(curr->data) != seen.end())
            {
                // Duplicate found, remove it
                prev->next = curr->next;
                delete curr;  // Free the memory of the removed node
            }
            else
            {
                // Not a duplicate, add to set and move prev pointer
                seen.insert(curr->data);
                prev = curr;
            }
            curr = prev->next;
        }
        
        return head;
    }
};

int main() {
    int T;
    cin >> T;
    
    while(T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = NULL;
 
        for(int i = 0; i < K; i++) {
            int data;
            cin >> data;
            if(head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        
        Solution ob;
        Node *result  = ob.removeDuplicates(head);
        print(result);
    }
    return 0;
}
