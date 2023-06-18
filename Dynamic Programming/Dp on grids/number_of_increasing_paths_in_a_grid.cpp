#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int n;
int m;
int mod = 1e9+7;
vector<int>dx={0,0,1,-1};
vector<int>dy={1,-1,0,0};

    int helper(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(i<0 ||i>=n || j<0 || j>=m )
        return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 1;
        for(int k=0;k<4;k++)
        {
            int row = i + dx[k];
            int col = j + dy[k];

            if(row>=0 && row<n && col>=0 && col<m && grid[row][col]>grid[i][j])
            {
               ans = (ans + helper(row,col,grid,dp))%mod; 
            }
        }
        return dp[i][j] =  ans%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        n =grid.size();
        m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        int paths=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                paths = (paths +  helper(i,j,grid,dp))%mod;
            }
        }
        return paths%mod;

    }
};