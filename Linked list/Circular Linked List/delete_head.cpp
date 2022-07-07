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
//naive
node *deleteHead(node *head)
{
    if(head==NULL)
    return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    node *curr=head;
    while(curr->next!=head)
    {
        curr=curr->next;
    }
    curr->next=head->next;
    delete head;
    return curr->next;
    

}
//efficient solution

node* delHead(node *head)
{
    if(head==NULL)
    return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }

    node *curr=head;//deleting the node after head, copying its data in head
    head->data=head->next->data;
    node *temp=head->next;
    head->next=head->next->next;
    delete temp;
    return head;//takes O(1) time
}

void printing(node *head)
{
    if(head==NULL)
    return;
    cout<<head->data<<" ";
    for(node *p=head->next;p!=head;p=p->next)
    {
        cout<<p->data<<" ";
    }
}

int main()
{
    node *head=new node(10);
    node *temp1 = new node (20);
    node *temp2 = new node(30);

    head->next=temp1;
    temp1->next=temp2;
    temp2->next=head;
    head= deleteHead(head);
    printing(head);
}