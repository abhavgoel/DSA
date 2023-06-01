#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void dfs(int node , vector<int>&vis,vector<vector<int>>&adjlist)
{
    vis[node]=1;
    for (auto i:adjlist[node])
    {
        if(vis[i]==0)
        dfs(i,vis,adjlist);
    }
}

void bfs(int node , vector<int>&vis,vector<vector<int>>&adjlist)
{
    queue<int>q;
    q.push(node);
    vis[node]=1;

    while(q.empty()==false)
    {
        int curr = q.front();
        q.pop();

        for(auto i:adjlist[curr])
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                q.push(i);
            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>>adjlist(v+1);
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        vector<int>vis(v+1);

        int count =0;
        for(int i=0;i<v;i++)//to check for all nodes present
        {
            if(vis[i]==0)
            {
                count++;
                bfs(i,vis,adjlist);
            }
        }
        return count;
    }
};