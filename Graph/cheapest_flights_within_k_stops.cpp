#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>graph(n);

        for(auto i:flights)
        {
            graph[i[0]].push_back({i[1],i[2]});
        }

        queue<pair<int,pair<int,int>>>q;//{stops,{node,edgeWt}}
        //using a normal queue bcoz the stops would be uniformly increasing , 
        //so priority queue wont help
        
        vector<int>dist(n,1e9);

        dist[src]=0;
        q.push({0,{src,0}});

        while(q.empty()==false)
        {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops>k)break;

            for(auto it:graph[node])
            {
                int adjNode = it.first;
                int edgeWt = it.second;

                if(cost + edgeWt < dist[adjNode])
                {
                    dist[adjNode] = edgeWt + cost;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dst]==1e9)return -1;
        else return dist[dst];

    }
};