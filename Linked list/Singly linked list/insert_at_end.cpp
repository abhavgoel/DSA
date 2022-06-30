#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;

    node(int x)
    {
        data =x;
        next=NULL;
    }
};

void printing(node *head)
{
    node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<endl;
        curr=curr->next;

    }
}

node *insertEnd(node *head,int x)
{
    node *temp=new node(x);

    node *curr=head;
    if(curr==NULL)
    {
        return temp;
    }
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    return head;
   

    


}


int main()
{
    node *head = NULL;
    //node *temp1 = new node(20);
    //node *temp2 = new node(30);

    // head->next = temp1;
    // temp1->next=temp2;
   // printing(head);
    head = insertEnd(head,5);
     printing(head);
    

}