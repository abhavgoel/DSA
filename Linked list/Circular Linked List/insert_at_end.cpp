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

node *insert_at_end(node *head,int x)
{
    node *temp = new node(x);

    if(head==NULL)
    temp->next=temp;

    else
   { 
        node *curr=head;
        while(curr->next!=head)
            curr=curr->next;

        curr->next=temp;
        temp->next=head;
    }
    return head;

}

//efficient solution
node *insertEnd(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }

    else
    {
        temp->next=head->next;
        head->next=temp;
        int t= head->data;//swapping
        head->data=temp->data;
        temp->data=t;
        return temp;
    }

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
    head= insertEnd(head ,5);
    printing(head);
}