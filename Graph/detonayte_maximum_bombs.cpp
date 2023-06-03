#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node , vector<int>&vis,vector<vector<int>>&graph,int &count)
    {
        vis[node]=1;
        count++;

        for(auto i:graph[node])
        {
            if(vis[i]==0)
            dfs(i,vis,graph,count);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size();
        vector<vector<int>>graph(n);
        for(int i=0;i<n;i++)
        {
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            int r = bombs[i][2];

            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];

                if((long long)abs(x1-x2)*(long long)abs(x1-x2) + (long long)abs(y1-y2)*(long long)abs(y1-y2)<=(long long)r*r)
                {
                    graph[i].push_back(j);//directed graph because radius from A to B might 
                    //be r but not vice versa
                }
            }
        }
        int res =0;
        for(int i=0;i<n;i++)
        {
            int count=0;
            vector<int>vis(n,0);
            vis[i]=1;
            dfs(i,vis,graph,count);
            res = max(res,count);
        }
        return res;


    }
};

