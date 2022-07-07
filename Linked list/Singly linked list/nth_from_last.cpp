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


void printNthFromEnd(node *head,int n)
{
    int len=0;
    for(node *curr=head;curr!=NULL;curr=curr->next)
        len++;

    if(len<n)
        return;
    node *curr=head;
    for(int i=1;i<len-n+1;i++)
        curr=curr->next;

    cout<<curr->data<<" ";
}

//efficient solution
//one traversal
void printNth(node *head,int n)
{
    if(head==NULL)return;
    node *first=head;
    for(int i=0;i<n;i++)
    {
        first=first->next;
    }
    node *second=head;
    while(first!=NULL)
    {
    first=first->next;
    second=second->next;
    }
    cout<<second->data;

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
    printNthFromEnd(head,2);
    printNth(head,2);
 

}