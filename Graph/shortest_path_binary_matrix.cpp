#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int>dx={0,0,1,-1,1,-1,1,-1};
    vector<int>dy={1,-1,0,0,1,-1,-1,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
        if(grid.size()==1&&grid[0].size()==1 && grid[0][0]==0)return 1;

        queue<pair<pair<int,int>,int>>q;//{{i,j},d}
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        q.push({{0,0},1});
        vis[0][0]=1;
        
        while(q.empty()==false)
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            
            q.pop();

            for(int k=0;k<8;k++)
            {
                int row = r + dx[k];
                int col = c + dy[k];

                if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() 
                && grid[row][col]==0 && vis[row][col]==0 )
                {
                    if(row==n-1 && col==m-1)
                    return d+1;

                    vis[row][col]=1;
                    q.push({{row,col},d+1});
                }

            }
        }
        return -1;
    }
};