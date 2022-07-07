#include<bits/stdc++.h>
using namespace std;

/*---*/

struct node{
    int data;
    node *next;
    node(int x)
    {
        data=x;
        next=NULL;
    }

};

node *reverse(node *head)
{
    node *curr=head;
    node *prev=NULL;
    while(curr!=NULL)
    {
        node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;//prev is the new head

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
    head->next=new node(20);
    head->next->next=new node (30);
    head->next->next->next=new node(40);
    head=reverse(head);
    printing(head);
   
    return 0;
}