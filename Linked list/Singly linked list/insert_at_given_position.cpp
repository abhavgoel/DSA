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

node* insertAtGiven(node *head,int pos,int data)
{
    node *temp = new node(data);
    if(pos==1)
    {
        temp->next=head;
        head=temp;
        return head;

    }
    node *curr=head;

    for(int i=1;i<=pos-2 && curr!=NULL;i++)
    {
        curr=curr->next;

    }
    if(curr==NULL)// if it is to be added at a position not in linked list
    {
        return head;
    }
    temp->next=curr->next;//so we dont lose track of linked list after the position to be added
    curr->next=temp;
    return head;



}


int main()
{
    node *head = new node(10);
    node *temp1 = new node(20);
    node *temp2 = new node(30);

     head->next = temp1;
     temp1->next=temp2;
    head=  insertAtGiven(head,3,5);
    
    printing(head);
    

}