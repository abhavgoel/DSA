#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data =x;
        next=NULL;

    }
};
//iterative solution
int search(Node *head,int x)
{
    int pos=1;
    Node *curr=head;
    while(curr!=NULL)
    {
        if(curr->data==x)
        return pos;
        else 
        {
         pos++;
         curr=curr->next;
        }
    }
    return -1;//if not present of list in empty
    
}
//recursive solution
int search1(Node *head,int x)
{
    if(head==NULL)
    return -1;
    if(head->data==x)
    return 1;
    else
    {
        int res=search(head->next,x);
        if(res==-1) return -1;
        else return (res+1);
    }
}


int main()
{
    int x;
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node (30);
    head->next->next->next=new Node(40);
    cout<<"Enter the data you want to search"<<endl;
    cin>>x;
    cout<<"by iterative "<<search(head,x)<<endl;
    cout<<"by recursive "<<search1(head,x)<<endl;
    return 0;
    
}
 