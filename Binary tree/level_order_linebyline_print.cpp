#include<bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    node(int k)
    {
        key=k;
        left=right=NULL;
    }
};

void levelOrderLine(node *root)
{
    if(root ==NULL)
    return;
    queue<node *>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1)
    {
        node *curr=q.front();
        q.pop();
        if(curr==NULL)
        {
            cout<<"\n";
            q.push(NULL);
            continue;
        }
        cout<<curr->key<<" ";
        if(curr->left!=NULL)
        q.push(curr->left);
        if(curr->right!=NULL)
        q.push(curr->right);

    }
}
void levelOrder(node *root)
{
    if(root==NULL)
    return;
    queue<node*>q;
    q.push(root);
    while(q.empty()==false)
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            node *curr=q.front();
            q.pop();
            cout<<curr->key<<" ";
            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right!=NULL)
            q.push(curr->right);
        }
        cout<<"\n";
    }
}

int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
   

    levelOrderLine(root);
    //levelOrder(root);
}