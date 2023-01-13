#include<bits/stdc++.h>
using namespace std;
struct node
{
    int key;
    struct node *left;
    struct node *right;
    node (int k)
    {
        key=k;
        left=right=NULL;
    }
};
int height(node *root)
{
    if(root==NULL)
    return 0;
    return 1+max(height(root->left),height(root->right));
}
bool isBalanced(node *root)//O(n^2) solution
{
    if(root==NULL)
    return true;
    int lh=height(root->left);
    int rh=height(root->right);
    return(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right));
   
}

//O(n) solution

int isBalanced2(node *root)
{
    if(root==NULL)
    return 0;
    int lh=isBalanced2(root->left);
    if(lh==-1) return -1;
    int rh=isBalanced2(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    else return 1+max(lh,rh);
}
int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->left->left->left=new node(40);
    root->left->right->right=new node(50);
    cout<<isBalanced2(root);
}