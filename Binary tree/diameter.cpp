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

int height(node *root)
    {
        if(root==NULL)
            return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        
        int ans= max(lh,rh)+1;
        return ans;
    }
    int diameterOfBinaryTree(node* root) {
        if(root==NULL)
            return 0;
        int d1=1+height(root->left)+height(root->right);
        
        int d2=diameterOfBinaryTree(root->left);
        int d3=diameterOfBinaryTree(root->right);
        return max(d1,max(d2,d3));
    }
    int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    
    cout<<diameterOfBinaryTree(root);
}