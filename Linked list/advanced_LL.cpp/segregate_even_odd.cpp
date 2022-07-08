#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};

node* seg(node *head)
{
    node *es=NULL;
    node *ee=NULL;
    node *os=NULL;
    node *oe=NULL;
    for(node *curr=head;curr!=NULL;curr=curr->next)
    {
        int x=curr->data;
        if(x%2==0)
        {
            if(es==NULL)
            {
                es=curr;
                ee=es;
            }
            else
            {
                ee->next=curr;
                ee=ee->next;
            }
        }
        else
        {
            if(os==NULL)
            {
                os=curr;
                oe=os;
            }
            else
            {
                oe->next=curr;
                oe=oe->next;
            }
        }
    }

    if(os==NULL||es==NULL)
    return head;
    ee->next=os;
    oe->next=NULL;
    return es;

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
    node *head= new node(10);
    node *temp1=new node(21);
    node *temp2=new node(30);
    node *temp3=new node(31);
    node *temp4=new node(40);
    node *temp5=new node(41);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    temp4->next=temp5;
    head=seg(head);
    printing(head);
    return 0;
}