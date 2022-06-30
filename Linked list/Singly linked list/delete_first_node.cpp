#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;

    node(int x)
    {
        data =x;
        next=NULL;
    }
};

void printing(node *head)
{
    node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<endl;
        curr=curr->next;

    }
}

node* deleteFirst(node *head)
{
    if(head==NULL)
        return NULL;
    else
    {
        node *temp;
        temp=head->next;
        delete head;
        return temp;
    }
}


int main()
{
    node *head = new node(10);
    node *temp1 = new node(20);
    node *temp2 = new node(30);

     head->next = temp1;
     temp1->next=temp2;
    head=  deleteFirst(head);
    
    printing(head);
    

}