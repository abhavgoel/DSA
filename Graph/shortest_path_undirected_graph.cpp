#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>>graph(N);
        for(int i=0;i<M;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<int>dist(N,1e9);
        dist[src]=0;
        queue<int>q;
        q.push(src);
        
        while(q.empty()==false)
        {
            int node = q.front();
            
            q.pop();
            
            for(auto i:graph[node])
            {
                if(dist[node] + 1 < dist[i])
                {
                    dist[i] = 1+dist[node];
                    q.push(i);
                }
                
                
            }
        }
        for(int i=0;i<N;i++)
        {
            if(dist[i]==1e9)
            dist[i]=-1;
        }
        return dist;
    }