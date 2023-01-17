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


void findDeepest(node *root,int &ans,int level,node* &value)
    {
        if(root==NULL)
            return ;
      
        
        if(level>ans)
        {
            ans=level;
            value=root;
        }
        findDeepest(root->left,ans,level+1,value);
        findDeepest(root->right,ans,level+1,value);
        
    }



int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);


    int ans=-1;
        int level=0;
        node * value=new node(0);
        findDeepest(root,ans,level,value);
        cout<<value->key;
        
    
}