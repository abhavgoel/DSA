#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;//self referential structure....it shoud have address of next node...so its type is Node
    Node(int x)
    {
        data =x;
        next=NULL;

    }
};
int main()
{
    Node *head= new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);
    head->next=temp1;
    temp1->next=temp2;
    return 0;
}
//for shorter implementation
/*
int main()
{
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    return 0;
}
*/