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



 node *push(node *head, int newData) {
            node *newNode= new node();
            newNode->data=newData;
            newNode->next=head;
            head=newNode;
            return head;
    }

int main(){

    node *head=NULL;
    head=push(head,5);
    head=push(head,7);

    printList(head);
    
     
}