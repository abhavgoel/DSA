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
void printk(node *root,int k)
{
    if(root==NULL)
    return;
    if(k==0)
    cout<<root->key<<" ";
    else
    {
        printk(root->left,k-1);
        printk(root->right,k-1);
    }
}