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
node *delLast(node *head)
{
    if(head==NULL)
    return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    node *curr=head;
    while(curr->next->next!=head)
    {
        curr=curr->next;
    }
    delete curr->next;
    curr->next=head;
    return head;
    

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
    head= delLast(head);
    printing(head);
}