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
//inorder
node *prevv=NULL;
node* BinToLL(node *root)
{
  
    if(root==NULL)
    return root;

    node *head=BinToLL(root->left);//left subtree process

    if(prevv==NULL)//root node
    head=root;

    else{
        root->left=prevv;
        prevv->right=root;
    }
    prevv=root;

    BinToLL(root->right);//right subtree process
    return head;



}
