#include <iostream>
using namespace std;


struct node{
    int data;
    node *next;
    node *prev;//<--
};



void printList (node *n){
   
    while(n!=NULL){
        cout<<n->data<<endl;
        n = n->next;
        
    }
   
}

/*-------  Insert node in Doubly Linked List  ------- */

void push(node **head_ref, int new_data){
    
    node *new_node = new node();
    new_node->data=  new_data;
    new_node->next = *head_ref;
    new_node->prev = NULL;
    
    if((*head_ref) != NULL){
        (*head_ref)->prev = new_node;
    }
    
    *head_ref = new_node;
}


int main(){
    
    node *head= NULL;
    push(&head, 4);
    push(&head, 11);
    push(&head, -3);
    
    // -3 11 4
    
    printList(head);
}