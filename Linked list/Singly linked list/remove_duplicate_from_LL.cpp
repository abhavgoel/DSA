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

node *remDups(node *head)
{
node *curr=head;
while(curr!=NULL&&curr->next!=NULL)//curr!=NULL for case when head==NULL
{
    if(curr->data==curr->next->data)
    {
        node *temp=curr->next;
        curr->next=curr->next->next;
        delete(temp);
        

    }
    else
    {
        curr=curr->next;
        
    }
    
}
return head;

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
    head->next=new node(10);
    head->next->next=new node (10);
    head->next->next->next=new node(10);
    head=remDups(head);
    printing(head);
   
    return 0;
}