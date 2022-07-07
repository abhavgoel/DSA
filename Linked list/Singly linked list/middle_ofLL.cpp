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
void printMiddle(node *head)
{
    if(head==NULL)
     return ;
    int count=0;
    node *curr;
    for(curr=head;curr!=NULL;curr=curr->next)
    {
        count++;
    }
    curr=head;
    for(int i=0;i<count/2;i++)
    {
        curr=curr->next;
    }
    cout<<curr->data;
    
    
}

//efficient solution
//one traversal
void printMid(node *head)
{
    if(head==NULL)
    return;
    node *slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data;
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
 
    printMiddle(head);
    printMid(head);
}