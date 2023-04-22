#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int helper(int row,int col,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp)
{
    if(row==0&&col==0 &&obstacleGrid[0][0]!=1)
    {
        return 1;
    }
    if(row<0||col<0)
    return 0;

    if(obstacleGrid[row][col]==1)
    return 0;

    if(dp[row][col]!=-1)return dp[row][col];

    int l=helper(row-1,col,obstacleGrid,dp);

    int r=helper(row,col-1,obstacleGrid,dp);

    return dp[row][col] = l+r;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        //return helper(m-1,n-1,obstacleGrid,dp);

        dp[0][0]=1;

    for(int row=0;row<m;row++)
    {
        for(int col=0;col<n;col++)
        {
            if(obstacleGrid[row][col]==1)dp[row][col]=0 ;

            else if(row==0&&col==0)continue;

            else
            {
            if(row>0)
                dp[row][col] += dp[row-1][col];
            if(col>0)
                dp[row][col]+=dp[row][col-1];
            }
        }
    }
    return dp[m-1][n-1];
    }
};

