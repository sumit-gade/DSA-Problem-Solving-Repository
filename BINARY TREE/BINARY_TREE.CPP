#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

/*node* newNode(int data)
{
    node* element= new node();
    element->data=data;
    element->left=NULL;
    element->right=NULL;

    return element;
}*/

node* newNode(int data)
{
    node* node= new  struct node();  // name same as node with strcut keyword
    node->data=data;
    node->left=NULL;
    node->right=NULL;

    return node;

}

void printNode(node *n)
{
     while(n!=NULL)
     {
        cout<<n->data<<" ";
        n=n->right;
       
     }
}

int main(){

    node* root = newNode(1);

    root->left=newNode(2);

    root->right=newNode(3);

    printNode(root);

    
    
     return 0;
}