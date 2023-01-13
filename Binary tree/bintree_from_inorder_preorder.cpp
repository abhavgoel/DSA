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
int preIndex=0;

node *ctree(vector<int>&inorder,vector<int>&preorder,int inStart,int inEnd)
{
    node *root=new node(preorder[preIndex++]);

    if(inStart>inEnd)
    return NULL;

    int inIndex;
    for(int i=inStart;i<=inEnd;i++)
    {
        if(inorder[i]==root->key)
        {
            inIndex=i;
            break;

        }
    }
    //int inIndex=m[root->val]; if we want to use a map for index searching

    root->left=ctree(inorder,preorder,inStart,inIndex-1);
    root->right=ctree(inorder,preorder,inIndex+1,inEnd);
    return root;

}
