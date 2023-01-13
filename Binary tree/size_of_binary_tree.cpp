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

int sizeBinaryTree(node *root)
{
    if(root==NULL)
    return 0;
    else 
    {
        return sizeBinaryTree(root->left)+sizeBinaryTree(root->right)+1;
    }
}
int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    cout<<sizeBinaryTree(root);
}