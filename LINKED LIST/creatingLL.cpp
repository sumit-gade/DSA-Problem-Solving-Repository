#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void printList(node *n)
{
    while(n!=NULL)
    {
        cout<<n->data<<endl;
        n=n->next;
    }
}


int main(){

    node *head=new node();
    node *first=new node();
    node *second=new node();

    head->data=1;
    head->next=first;

    first->data=2;
    first->next=second;

    second->data=3;
    second->next=NULL;

    printList(head);
    
     return 0;
}