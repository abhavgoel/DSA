#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  vector<int>dx={1,-1,0,0};
  vector<int>dy={0,0,1,-1};
  void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid,int baserow,int basecol,vector<pair<int,int>>&v)
  {
      if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j]==1 || grid[i][j]==0)
      return;
      
      vis[i][j]=1;
      v.push_back({i-baserow,j-basecol});
      
      for(int k=0;k<4;k++)
      {
          dfs(i+dx[k],j+dy[k],vis,grid,baserow,basecol,v);
      }
      
      
      
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>>st;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    vector<pair<int,int>>v;
                    dfs(i,j,vis,grid,i,j,v);
                    st.insert(v);
                }
            }
        }
        
        return st.size();

    }
};
