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

bool childrenSum(node *root)
{
    if(root==NULL)
    return true;
    if(root->left==NULL && root->right==NULL)
    return true;

    int sum=0;
    if(root->left!=NULL)
    sum=sum+root->left->key;
    if(root->right!=NULL)
    sum=sum+root->right->key;

    return (root->key==sum && childrenSum(root->left) && childrenSum(root->right));

}