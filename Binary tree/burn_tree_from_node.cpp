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
int findMaxDistance(map<node*,node*> &mp,node *target)
{
    
    queue<node*>q;
    q.push(target);
    map<node*,int>visited;

    visited[target] =1;
    int maxi=0;

    while(!q.empty())
    {
        int flag=0;
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            node *curr=q.front();
            q.pop();

            if(curr->left && !visited[curr->left])
            {
                flag=1;
                visited[curr->left] =1 ;
                q.push(curr->left);
            }

            if(curr->right && !visited[curr->right])
            {
                flag=1;
                visited[curr->right]=1;
                q.push(curr->right);
            }

            if(mp[curr] && !visited[mp[curr]])
            {
                flag=1;
                visited[mp[curr]]=1;
                q.push(mp[curr]);
            }

        }
        if(flag==1)
        maxi++;
    }
    return maxi;



}

node *bfsToMapParents(node *root,map<node*,node*>&mp,int start)
{
    queue<node*>q;
    q.push(root);
    node *res;
    while(!q.empty())
    {
        node *curr=q.front();
        q.pop();
        if(curr->key==start)
        res=curr;

        if(curr->left)
        {
            mp[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right)
        {   
            mp[curr->right]=curr;
            q.push(curr->right);
        }
    }
    return res;
}
int main()
{
 node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    cout<<"data of node to burn tree from ";
    int start;
    cin>>start;


    map<node*,node*> mp;

    node* target = bfsToMapParents(root,mp,start);

    int maxi=findMaxDistance(mp,target);
    cout<<maxi;

}