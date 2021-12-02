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
void printing(node *head)
{
    node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data;
        curr=curr->next;
    }
}
void recur_printing(node *head)
{
    if(head==NULL)
    return ;
    cout<<head->data<<" ";
    recur_printing(head->next);
} //auxillary space of O(n)
int main()
{
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node (30);
    head->next->next->next=new node(40);
    printing(head);
    cout<<endl;
    recur_printing(head);
    return 0;
}