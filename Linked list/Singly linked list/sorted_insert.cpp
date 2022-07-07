#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node (int x)
    {
        data=x;
        next=NULL;

    }
};

node *sortedInsert(node *head,int x)
{
    node *temp=new node (x);
    if(head==NULL)
    return temp;
    if(x<head->data)
    {
        temp->next=head;
        return temp;
    }

    node *curr=head;
    while(curr->next!=NULL && curr->next->data<x)
    {
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}
void printing(node *head)
{
    node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}
int main()
{
    node *head=new node(10);
    node *temp1=new node(20);
    node *temp2=new node(30);
    head->next=temp1;
    temp1->next=temp2;
    head=sortedInsert(head,15);
    printing(head);
}