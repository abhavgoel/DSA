#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n+1);//1 based indexing
        
        for(int i=0;i<m;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
            
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//{node,dist}
        vector<int>dist(n+1,1e9);
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++)parent[i]=i;
        
        dist[1]=0;
        pq.push({1,0});
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            
            int node = it.first;
            int d = it.second;
            
            for(auto i:adj[node])
            {
                int adjNode = i.first;
                int edgeWt = i.second;
                
                if(dist[node] + edgeWt<dist[adjNode])
                {
                    dist[adjNode] = dist[node] + edgeWt;
                    pq.push({adjNode,dist[adjNode]});
                    
                    parent[adjNode] = node;
                }
            }
        }
        if(dist[n]==1e9)return {-1};
        vector<int>path;
        int node = n;//starting from back
        while(parent[node]!=node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        
        return path;
}