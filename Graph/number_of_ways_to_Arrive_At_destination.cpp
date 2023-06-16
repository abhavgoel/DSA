#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll,ll>>graph[n];
        for(int i=0;i<roads.size();i++)
        {
            ll u = roads[i][0];
            ll v = roads[i][1];
            ll time = roads[i][2];

            // graph[i[0]].push_back({i[1],i[2]});
            // graph[i[1]].push_back({i[0],i[2]});

            graph[u].push_back({v,time});
            graph[v].push_back({u,time});

        }

        vector<ll>dist(n,LONG_MAX);
        vector<ll>ways(n,LONG_MAX);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

        pq.push({0,0});

        while(pq.empty()==false)
        {
            ll node = pq.top().second;
            ll d = pq.top().first;
            pq.pop();

            for(auto it:graph[node])
            {
                ll adjNode = it.first;
                ll edgeWt = it.second;
                if(edgeWt + d <dist[adjNode])
                {
                    //first time visiting with this short distance
                    dist[adjNode] = edgeWt + d;
                    pq.push({dist[adjNode],adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(edgeWt + d == dist[adjNode])
                {
                    
                    ways[adjNode]+=ways[node]%mod;
                }

            }
        }
      // cout<<dist[n-1];
        return ways[n-1]%mod;
    }
};