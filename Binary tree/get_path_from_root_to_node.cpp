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

bool getPath(node *root,vector<int>&arr,int x)
{
    if(root==NULL)
    return false;

    arr.push_back(root->key);
    if(root->key==x)
    return true;

    if(getPath(root->left,arr,x) || getPath(root->right,arr,x))
        return true;

    arr.pop_back();
    return false;
    
}

int main()

{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    
    vector<int>arr;
    int x=40;
    getPath(root,arr,x);

    for(auto i:arr)
    cout<<i<<" ";
}
