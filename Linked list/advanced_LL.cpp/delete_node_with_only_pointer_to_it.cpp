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

void del(node *ptr)//trick is to copy content of next node and delete the next node
{
    node *temp=ptr->next;
    ptr->data=temp->data;
    ptr->next=temp->next;
    delete temp;

}

int main()
{
    node *head= new node(10);
    node *temp1=new node(20);
    node *temp2=new node(30);
    head->next=temp1;
    temp1->next=temp2;
    return 0;
}