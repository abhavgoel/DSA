#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<int>dx={1,-1,0,0};
vector<int>dy={0,0,1,-1};

void dfs(int i,int j, vector<vector<int>>&vis,vector<vector<int>>&grid)//dfs to mark all 1's of the first island
{
    if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||vis[i][j]==1||grid[i][j]==0)
    return ;

    vis[i][j]=1;

    for(int k=0;k<4;k++)
    {
        int r = i + dx[k];
        int c = j + dy[k];

        dfs(r,c,vis,grid);
    }
}
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        bool flag=false;
        //----------------marking the first island------------------
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(i,j,vis,grid);
                    flag=true;
                    break;
                }
            }
            if(flag==true)
            break;
        }

        //------pushing 1st island nodes into queue to perform bfs------------------
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==1)
                q.push({{i,j},0});
            }
        }

        //-------bfs----------------------------
        
        while(q.empty()==false)
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            
            q.pop();

            for(int k=0;k<4;k++)
            {
                int r = x + dx[k];
                int c = y + dy[k];


                if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && vis[r][c]==0)
                {
                    if(grid[r][c]==1)
                    return d;

                    vis[r][c]=1;
                    q.push({{r,c},d+1});
                }
            }
        }
        return -1;
    }
};