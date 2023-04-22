#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int helper(int index,int last,vector<vector<int>>&grid,int n,vector<vector<int>>&dp)
{
    if (index==0)
    {
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(i!=last)
            {
                mini = min(mini,grid[index][i]);
            }
        }
        return mini;
    }
    if(dp[index][last]!=-1)return dp[index][last];

    int mini= INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(i!=last)
        {
            mini=min(mini,(grid[index][i] + helper(index-1,i,grid,n,dp)));
        }
    }
    return dp[index][last]= mini;
}

    

    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();

        vector<vector<int>>dp(n+1,vector<int>(n+1,1e8));
        //return helper(n-1,n,grid ,n,dp);

        for(int i=0;i<n;i++)
        {
           for(int j=0;j<n;j++)
           {
               if(j==i)continue;
               dp[0][i] = min(dp[0][i],grid[0][j]);
           }
        }

        // for(int i=0;i<n;i++)
        // {
        //     cout<<dp[0][i]<<" ";
        // }
        if(grid.size()==1&&grid[0].size()==1)return grid[0][0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(k!=j)
                    {
                        dp[i][j] = min(dp[i][j] , (grid[i][k] + dp[i-1][k]));
                    }
                }
            }
        }

        return dp[n-1][n];
    }
};