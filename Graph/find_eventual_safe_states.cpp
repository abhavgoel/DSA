#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
bool dfs(int node,vector<int>&vis,vector<int>&pathVis,vector<int>&check,vector<vector<int>>&graph)
{
    vis[node]=1;
    pathVis[node]=1;

    for(auto i:graph[node])
    {
        if(vis[i]==0)
        {
            if(dfs(i,vis,pathVis,check,graph)==true)
            {
                check[i]=0;
                return true;
            }

            
        }
        else if(vis[i]==1 && pathVis[i]==1)
        {
            check[i]=0;
            return true;
        }
    }
    check[node]=1;
    pathVis[node]=0;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //every node that is part of a cycle could not be a safe node

        // every node pointing to a cycle can also not be a safe node

        int v = graph.size();
        vector<int>vis(v,0);
        vector<int>pathVis(v,0);

        vector<int>check(v,0);
        vector<int>ans;

        for(int i=0;i<v;i++)
        {
            if(vis[i]==0)
            dfs(i,vis,pathVis,check,graph);
        }

        for(int i=0;i<v;i++)
        {
            if(check[i]==1)ans.push_back(i);

        }
        return ans;
    }
};