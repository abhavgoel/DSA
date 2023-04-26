#include<bits/stdc++.h>
using namespace std;

//graph whcih can be colored by 2 colors , but no two adjacent nodes can have the same color

//linear graphs are bi partite

//graph with even cycle lengths are bipartite

//odd cycle graph cant be bipartite

class Solution {
public:
bool bfs(int node , vector<vector<int>>&graph,vector<int>&color)
{
    queue<int>q;
    q.push(node);
    color[node]=0;

    while(q.empty()==false)
    {
        int curr = q.front();
        q.pop();

        for(auto i:graph[curr])
        {
            if(color[i]==-1)//if adjacent node not yet colored give the color opposite of parent
            {
                color[i]=!color[curr];
                q.push(i);
            }

            else if(color[i]==color[curr])
            return false;

        }
    }
    return true;
}

    bool dfs(int node,int clr,vector<int>&color,vector<vector<int>>&graph)
    {
        color[node]=clr;

        for(auto i:graph[node])
        {
            if(color[i]==-1)
            {
                if(dfs(i,!clr,color,graph)==false)
                return false;
            }

            else if(color[i]==clr)return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>color(v,-1);

        for(int i=0;i<v;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i,0,color,graph)==false)
                return false;
            }
        }
        return true;
        
    }
};