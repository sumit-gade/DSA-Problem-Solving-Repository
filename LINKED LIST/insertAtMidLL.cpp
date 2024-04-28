#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

void printList(node *n)
{
    while(n!=NULL)
    {
        cout<<n->data<<endl;
        n=n->next;
    }
}



 /*node *push(node *head, int newData) {
            node *newNode= new node();
            newNode->data=newData;
            newNode->next=head;
            head=newNode;
            return head;
    }*/

    void push(node **head_ref,int newData)
    {
        node *newNode=new node();
        newNode->data=newData;
        newNode->next=*head_ref;
        *head_ref=newNode;
    } 

    void insertAfter(node *prev_node,int newData)
    {
        node *newNode= new node();
        newNode->data=newData;
        newNode->next=prev_node->next;
        prev_node->next=newNode;
    }

   

int main(){

    node *head=NULL;
    push(&head,5);
    push(&head,7);
    push(&head,4);
    push(&head,3);

   

    insertAfter(head->next,79);
    

     printList(head);
    
     
}