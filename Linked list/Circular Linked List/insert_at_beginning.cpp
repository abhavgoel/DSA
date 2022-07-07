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

node *insert_at_begin(node *head,int x)
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
    return temp;

}
 // efficient solution
 //add a node after head, take O(1) time and swap head and that node

node *insertBegin(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
    temp->next=temp;
    else 
    {
        temp->next=head->next;
        head->next=temp;
        int t= head->data;//swapping
        head->data=temp->data;
        temp->data=t;
        
    }
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
    head= insert_at_begin(head ,5);
    printing(head);
    cout<<endl;
    head=insertBegin(head,5);
    printing(head);

}