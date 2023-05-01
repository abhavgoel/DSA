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

        //---------------------------------dfs--------------------------------------

        // int v = graph.size();
        // vector<int>vis(v,0);
        // vector<int>pathVis(v,0);

        // vector<int>check(v,0);
        // vector<int>ans;

        // for(int i=0;i<v;i++)
        // {
        //     if(vis[i]==0)
        //     dfs(i,vis,pathVis,check,graph);
        // }

        // for(int i=0;i<v;i++)
        // {
        //     if(check[i]==1)ans.push_back(i);

        // }
        // return ans;

        //-------------------------bfs----------------------------------------------

        //reverse the graph so that zero outdegree can become zero indegree and we can apply kahn's algo
        int v = graph.size();
        vector<vector<int>>adjrev(v);

        for(int i=0;i<v;i++)
        {
            for(auto it:graph[i])//i->it
            {
                adjrev[it].push_back(i);//it->i
            }
        }
        vector<int>indegree(v);
        for(int i=0;i<v;i++)
        {
            for(auto it:adjrev[i])
            {
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        vector<int>safe;
        while(q.empty()==false)
        {
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for(auto i:adjrev[node])
            {
                indegree[i]--;
                if(indegree[i]==0)
                q.push(i);
            }
        }
        sort(safe.begin(),safe.end());
        return safe;

    }
};