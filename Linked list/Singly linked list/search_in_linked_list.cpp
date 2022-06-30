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

int search(node *head,int x)
{
   node *curr=head;

   int pos=1;
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
   return -1;//if not present;


}


int main()
{
    node *head = new node(10);
    node *temp1 = new node(20);
    node *temp2 = new node(30);

     head->next = temp1;
     temp1->next=temp2;
    cout<<"element present at "<<search(head,20)<<endl;
    
    printing(head);
    

}