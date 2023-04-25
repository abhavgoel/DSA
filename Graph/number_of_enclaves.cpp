#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};
    void dfs(int i,int j , vector<vector<int>>&vis,vector<vector<int>>&grid)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j]==1 || grid[i][j]==0)
        return;

        vis[i][j]=1;
        for(int k=0;k<4;k++)
        {
            dfs(i+dx[k],j+dy[k],vis,grid);
        }



    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int count = 0;

        for(int i=0;i<n;i++)
        {
            if(vis[i][0]==0 && grid[i][0]==1)//first column
            dfs(i,0,vis,grid);

            if(vis[i][m-1]==0 &&grid[i][m-1]==1)//last column
            dfs(i,m-1,vis,grid);
        }

        for(int j=0;j<m;j++)
        {
            if(vis[0][j]==0 && grid[0][j]==1)//first row
            dfs(0,j,vis,grid);

            if(vis[n-1][j]==0 && grid[n-1][j]==1)//last row
            dfs(n-1,j,vis,grid); 
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                count++;
            }
        }
        return count;
    }
};