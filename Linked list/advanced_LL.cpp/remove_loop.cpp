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

void remLoop(node *head)
{
    node *slow_p=head;
    node *fast_p=head;

    while(fast_p!=NULL&&fast_p->next!=NULL)
    {
        slow_p=slow_p->next;
        fast_p=fast_p->next->next;
        if(slow_p==fast_p)
        break;
    }
    if(slow_p!=fast_p)
    return ;

    slow_p=head;
    while(slow_p->next!=fast_p->next)
    {
        slow_p=slow_p->next;
        fast_p=fast_p->next;
    }
    fast_p->next=NULL;
}

int main()
{
    node *head= new node(10);
    node *temp1=new node(20);
    node *temp2=new node(30);
    head->next=temp1;
    temp1->next=head;
    return 0;
}