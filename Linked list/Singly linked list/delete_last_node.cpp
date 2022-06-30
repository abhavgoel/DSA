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

node* deleteLast(node *head)
{
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    node *temp=head;
    while(temp->next->next!=NULL)
        temp=temp->next;
    delete (temp->next);
    temp->next=NULL;
    return head;


}


int main()
{
    node *head = new node(10);
    node *temp1 = new node(20);
    node *temp2 = new node(30);

     head->next = temp1;
     temp1->next=temp2;
    head=  deleteLast(head);
    
    printing(head);
    

}