#include<bits/stdc++.h>
using namespace std;
// only valid in directed acyclic graphs
void dfs(int node,vector<int>&vis,vector<int>&v,vector<int> adj[])
	{
	    vis[node]=1;
	    for(auto i:adj[node])
	    {
	        if(vis[i]==0)
	        dfs(i,vis,v,adj);
	        
	    }
	    v.push_back(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>vis(V,0);
	    stack<int>st;
	    vector<int>v;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==0)
	        dfs(i,vis,v,adj);
	    }
	    reverse(v.begin(),v.end());
	    return v;
	}