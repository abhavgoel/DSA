#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>adj[],int vis[],vector<int>&ds)
    {
        vis[node]=1;
        ds.push_back(node);
        
        for(auto i:adj[node])
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,ds);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V]={0};
        vector<int>ds;
        int start = 0;
        
        dfs(start,adj,vis,ds);
        return ds;
    }