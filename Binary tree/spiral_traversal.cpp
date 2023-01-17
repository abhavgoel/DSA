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

void printSpiral(node *root)
{
    if(root==NULL)
    return;

    queue<node*>q;
    stack<int>s;
    q.push(root);
    bool reverse =false;

    while(q.empty()==false)
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            node *curr=q.front();
            q.pop();

            if(reverse)
            s.push(curr->key);
            else cout<<curr->key<<" ";

            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);


        }
        if(reverse)
        {
            while(s.empty()==false)
            {
                cout<<s.top()<<" ";
                s.pop();
            }
        }
        reverse=!reverse;
        cout<<endl;
    }
}

void spiral(node *root)
{
    if(root==NULL)
    return;

    stack<node*>s1;
    stack<node*>s2;
    s1.push(root);

    while(s1.empty()==false || s2.empty()==false)
    {
        while(s1.empty()==false)
        {
            node *curr=s1.top();s1.pop();
            cout<<curr->key<<" ";
            if(curr->left)
            s2.push(curr->left);
            if(curr->right)
            s2.push(curr->right);

        }
        while(s2.empty()==false)
        {
            node *curr=s2.top();
            s2.pop();
            cout<<curr->key<<" ";

            if(curr->right)
            s1.push(curr->right);
            if(curr->left)
            s1.push(curr->left);
        }
    }
    {

    }
}
int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right->left=new node(40);
    root->right->right=new node(50);
    root->left->left->left=new node(40);
    root->left->right->right=new node(50);
  
    //printSpiral(root);
    spiral(root);
}