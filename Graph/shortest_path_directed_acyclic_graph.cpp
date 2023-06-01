#include<bits/stdc++.h>
using namespace std;

void topoSort(int node,stack<int>&st,vector<int>&vis,vector<vector<pair<int,int>>>&graph)
  {
      vis[node]=1;
      
      for(auto i:graph[node])
      {
          if(vis[i.first]==0)
          topoSort(i.first,st,vis,graph);
      }
      st.push(node);
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>>graph(N);
        for(int i=0;i<M;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            
            graph[u].push_back({v,d});
        }
        stack<int>st;
        
        vector<int>vis(N,0);
        for(int i=0;i<N;i++)
        {
            if(vis[i]==0)
            topoSort(i,st,vis,graph);
        }
        vector<int>dist(N,1e9);
        dist[0] = 0;
        while(st.empty()==false)
        {
            int node = st.top();
            st.pop();
            
            for(auto i:graph[node])
            {
                int v = i.first;
                int wt = i.second;
                
                if(dist[node] + wt < dist[v])
                dist[v]=dist[node] + wt;
            }
        }
        for(int i=0;i<N;i++)
        {
            if(dist[i]==1e9)
            dist[i]=-1;
        }
        return dist;
    }