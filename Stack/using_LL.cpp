#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data=x;
        next=NULL;
    }


};

struct Stack
{
    Node *head;
    int siz;
    Stack()
    {
        head=NULL;
        siz=0;
    }

    void push(int x)
    {
        Node *temp=new Node(x);
        temp->next=head;
        head=temp;
        siz++;
    }

    int pop()
    {
        if(head==NULL)
        return INT_MAX;

        int res=head->data;
        Node *temp=head;
        head=head->next;
        delete temp;
        siz--;
        return res;
    }
    int size()
    {
        return siz;
    }

    int peek()
    {
        if(head==NULL)
        return INT_MAX;

        return head->data;


    }
    bool isEmpty()
    {
        return(head==NULL);
    }

};