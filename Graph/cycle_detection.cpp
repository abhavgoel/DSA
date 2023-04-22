#include<bits/stdc++.h>
using namespace std;

bool dfs(int node , int parent , vector<int>&vis,vector<int>adj[])
    
    {
        vis[node] = 1;
        
        for(auto i:adj[node])
        {
            if(vis[i]==0)
            {
                if(dfs(i,node,vis,adj)==true)
                return true;
                
            }
            else if(vis[i] == 1 && i!=parent)//if node visited and not parent then its a cycle
            return true;
        }
    }
    
    bool bfs(int node,int parent , vector<int>&vis,vector<int>adj[])
    {
        queue<pair<int,int>>q;
        q.push({node,parent});
        vis[node]=1;
        
        while(q.empty()==false)
        {
            int curr= q.front().first;
            int par = q.front().second;
            q.pop();
            
            for(auto i:adj[curr])
            {
                if(vis[i]==0)
                {
                vis[i]=1;
                q.push({i,curr});//curr =parent for next node
                }
                else if(vis[i]==1 && i!=par)
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(bfs(i,-1,vis,adj)==true)
                return true;
            }
        }
        return false;
    }