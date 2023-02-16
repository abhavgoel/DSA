#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
long long helper(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&dp)
{
    if(row==0&&col==0)
    {
        return grid[0][0];
    }
    if(row<0 || col<0)
    return INT_MAX;
    if(dp[row][col]!=-1)return dp[row][col];

    long long up=grid[row][col] + helper(row-1,col,grid,dp);
    long long left = grid[row][col] + helper(row,col-1,grid,dp);

    return dp[row][col] = min(up,left);
}
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,0));

        //return helper(row-1,col-1,grid,dp);

        dp[0][0]=grid[0][0];

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0&&j==0)
                continue;
                long long up=grid[i][j];
                long long left=grid[i][j];
                if(i>0)
                 up +=  dp[i-1][j];
                 else
                 up+=INT_MAX;

                if(j>0)
                 left +=dp[i][j-1];
                 else
                 left+=INT_MAX;

                dp[i][j] = min(up,left);
            }

        }
        return dp[row-1][col-1];
    }
};