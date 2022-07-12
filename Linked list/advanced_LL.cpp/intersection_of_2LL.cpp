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
//first count nodes in both LL
//then subtract
//then move bigger LL the ans from substarction
int intersection(node *head,node *head1)
{
    node *curr=head;
    node *curr1=head1;
    while(curr!=NULL&&curr1!=NULL)
    {
        if(curr==curr1)
        cout<<curr->data;

        curr=curr->next;
        curr1=curr1->next;
    }
}


int main()
{
    node *head= new node(10);
    node *temp1=new node(20);
    node *temp2=new node(30);
     node *temp3=new node(40);
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    node *head1=new node(11);
    
    
    head1->next=temp2;
    intersection(head,head1);
    
    return 0;
}
