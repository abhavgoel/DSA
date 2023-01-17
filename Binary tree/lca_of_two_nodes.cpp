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

bool findPath(node* root,vector<int>&arr,int x)
{
    if(root==NULL)
    return false;

    arr.push_back(root->key);

    if(root->key==x)
    return true;

    if(findPath(root->left,arr,x) || findPath(root->right,arr,x))
    return true;

    arr.pop_back();
    return false;


}
int lca(node *root,int n1,int n2)
{
    vector<int>path1,path2;

    if(findPath(root,path1,n1)==false ||findPath(root,path2,n2)==false )
    return -1;

    for(int i=0;i<path1.size()-1 && i<path2.size()-1;i++)
    {
        if(path1[i+1]!=path2[i+1])
        return path1[i];
    }
    return -1;

}
int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);

    vector<int>path1,path2;
    findPath(root,path1,50);
    findPath(root,path2,40);
    for(auto i:path1)
    cout<<i<<" ";
    cout<<endl;
    for(auto i:path2)
    cout<<i<<" ";
    cout<<endl;
    cout<<"lca :"<<lca(root,40,50);

}