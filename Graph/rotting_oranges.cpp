#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<int>dx={1,-1,0,0};
vector<int>dy={0,0,1,-1};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>>q;//{{row,col},time}
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        int time = 0 ;

        while(q.empty()==false)
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(t,time);
            q.pop();
            for(int k=0;k<4;k++)
            {
                int row = r+dx[k];
                int col = c+dy[k];
                if(row>=0 && row<n && col>=0 && col<m && vis[row][col]!=1 && grid[row][col]==1)
                {
                    q.push({{row,col},t+1});
                    vis[row][col]=1;
                }

            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]!=1 && grid[i][j]==1)
                return -1;
            }
        }
        return time;
    }
};