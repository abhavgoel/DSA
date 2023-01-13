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
int maxlevel=0;
void printLeft(node *root,int level)
{
    if(root==NULL)
    return;
    if(maxlevel<level)
    {
        cout<<root->key<<" ";
        maxlevel=level;

    }
    printLeft(root->left,level+1);
    printLeft(root->right,level+1);

}
void printLeftView(node *root)
{
    printLeft(root,1);

}
int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    printLeftView(root);
}