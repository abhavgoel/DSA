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
node *delKth(node *head,int k)
{
    node *curr=head;
    for(int i=0;i<k-2;i++)
    {
        curr=curr->next;//pointer to prev node to be deleted

    }
    node *temp=curr->next;
    curr->next=curr->next->next;
    delete temp;
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
    head= delKth(head,2);
    printing(head);
}