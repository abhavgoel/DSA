#include<bits/stdc++.h>
using namespace std;

 int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>vis(V,0);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        //{wt,node}
        int sum = 0;
        while(pq.empty()==false)
        {
            auto it = pq.top();
            pq.pop();
            
            int wt=it.first;
            int node =it.second;
            if(vis[node]==1)continue;
            
            vis[node]=1;
            sum+=wt;
            for(auto i:adj[node])
            {
                int edgeWt=i[1];
                int adjNode= i[0];
                
                if(vis[adjNode]==0)
                {
                    pq.push({edgeWt,adjNode});
                }
            }
        }
        return sum;
    }