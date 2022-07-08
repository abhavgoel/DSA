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
node *reverseLL(node *head)
{
    //reverse LL
}
bool isPalindrome(node *head)
{
    if(head==NULL)
    return true;
    if(head->next==NULL)
    return true;

    node *slow=head;
    node *fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    node *rev=reverseLL(slow->next);

    node *curr=head;
    while(rev!=NULL)
    {
        if(rev->data!=curr->data)
        {
            return false;

        }
        rev=rev->next;
        curr=curr->next;
    }
    return true;
}