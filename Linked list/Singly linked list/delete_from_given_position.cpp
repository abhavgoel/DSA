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

node* deleteFromGiven(node *head,int pos)
{
    if(head==NULL)
        return NULL;
    else
    {
        node *temp=head;
        for(int i=1;i<=pos-2&&temp!=NULL;i++)
        {
            temp=temp->next;
        }
        if(temp==NULL)
        return head;

        node *curr=temp->next->next;
        delete temp->next;

        temp->next=curr;
        return head;

    }
}


int main()
{
    node *head = new node(10);
    node *temp1 = new node(20);
    node *temp2 = new node(30);

     head->next = temp1;
     temp1->next=temp2;
    head=  deleteFromGiven(head,3);
    
    printing(head);
    

}