#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//if cycle present then return false, because we cant perform topological sort


bool dfs(int node,vector<int>&vis,vector<int>&pathvis,vector<vector<int>>&adj)
{
    vis[node]=1;
    pathvis[node]=1;

    for(auto i:adj[node])
    {
        if(vis[i]==0)
        {
            if(dfs(i,vis,pathvis,adj)==true)
            return true;

            
        }
        else if(vis[i]==1 && pathvis[i]==1)
        return true;
    }
    pathvis[node]=0;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>>adj(numCourses);
        
        for(auto i:prereq)
        {
            adj[i[1]].push_back(i[0]);
        }
        // for(int i=0;i<adj.size();i++)
        // {
        //     for(int j=0;j<adj[i].size();j++)
        //     {
        //         cout<<i<<"-->"<<adj[i][j];
        //     }
        //     cout<<endl;
        // }
        //-----------part of dfs approach------------------------------
        // vector<int>vis(numCourses,0);
        // vector<int>pathvis(numCourses,0);



    //     for(int i=0;i<numCourses;i++)
    //     {
    //         if(vis[i]==0 && dfs(i,vis,pathvis,adj)==true)return false;
    //     }
       
    //    return true;


    //-------------------bfs/topological sort approach----------------------

    vector<int>indegree(numCourses,0);

    for(int i=0;i<numCourses;i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int>q;
    for(int i=0;i<numCourses;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    vector<int>topo;
    while(q.empty()==false)
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto i:adj[node])
        {
            indegree[i]--;
            if(indegree[i]==0)
            q.push(i);
        }

    }
    if(topo.size()==numCourses)return true;
    else return false;

    }
};