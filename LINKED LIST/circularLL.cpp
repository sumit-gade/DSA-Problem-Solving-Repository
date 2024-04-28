#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void printList(node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<endl;
        n=n->next;

    }
}

void printCiruclarList(node * first)
{
    node *temp=first;

    if(first!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;

        while (temp!=first)
        {                   
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        
    }
}

int main(){

    node *head=new node();
    node *second=new node();
    node *third=new node();
    node *fourth=new node();
    node *fifth=new node();
    node *sixth=new node();
    node *seventh=new node();
    node *eight=new node();
    node *ninth=new node();
    node *tenth=new node();
    

    head->data=1; head->next=second;
    second->data=2; second->next=third;
   third->data=3; third->next=fourth;
    fourth->data=4; fourth->next=fifth;
    fifth->data=5; fifth->next=sixth;
    sixth->data=6; sixth->next=seventh;
    seventh->data=7; seventh->next=eight;
   eight->data=8; eight->next=ninth;
    ninth->data=9; ninth->next=tenth;
    tenth->data=10; tenth->next=head;
    
    printCiruclarList(third);
    
    
    
}