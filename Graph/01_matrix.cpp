#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<int>dx={1,-1,0,0};
vector<int>dy={0,0,1,-1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                q.push({{i,j},0});
                vis[i][j]=1;

                }
            }
        }

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int distance = q.front().second;
            q.pop();

            dist[r][c]=distance;

            for(int k=0;k<4;k++)
            {
                int row = r + dx[k];
                int col = c + dy[k];

                if(row>=0 && row<n && col>=0 && col<m && vis[row][col]!=1 && mat[row][col]==1)
                {
                    q.push({{row,col},distance+1});
                    vis[row][col]=1;
                }
            }

        
        }

        return dist;

    }
};