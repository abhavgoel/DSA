#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
vector<int>dx={0,0,1,-1};
vector<int>dy={1,-1,0,0};
void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&grid)
{
    
    if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]=='1' && vis[i][j]==0)
    {
        vis[i][j]=1;
        grid[i][j]='0';
        

        for(int k=0;k<4;k++)
        {
            
            dfs(i+dx[k],j+dy[k],vis,grid);
            
        }
    }
  
}

void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&grid)
{
    vis[i][j]=1;
    queue<pair<int,int>>q;
    q.push({i,j});

    while(q.empty()==false)
    {

        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int k=0;k<4;k++)
        {
            int nrow = row + dx[k];
            int ncol = col +dy[k];

            if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size() && grid[nrow][ncol]=='1'&&vis[nrow][ncol]==0)
            {
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j]=='1')
                {
                    
                    count++;
                    bfs(i,j,vis,grid);
                    
                }
            }
        }
        return count;

    }
};