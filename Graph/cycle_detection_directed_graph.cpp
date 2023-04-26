#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&pathVis)
    {
        vis[node]=1;
        pathVis[node]=1;
        //traverse for adjacent nodes
        for(auto i:adj[node])
        {
            //when the node is not visited
            if(vis[i]==0)
            {
                if(dfs(i,adj,vis,pathVis)==true)
                return true;
            }
            //when node has been previously visited but has to be visited on the same path
            else if(vis[i]==1 && pathVis[i]==1)
                return true;
            
        }
        pathVis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(i,adj,vis,pathVis)==true)
                return true;
            }
        }
        return false;
    }