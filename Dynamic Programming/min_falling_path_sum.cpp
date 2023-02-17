#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
long long helper(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp)
{
    if(j<0)
    return INT_MAX;

    if(j>=matrix[0].size())
    return INT_MAX;

    if(i==0)
    return matrix[i][j];

   
    if(dp[i][j]!=-1)return dp[i][j];
    long long up = matrix[i][j] + helper(i-1,j,matrix,dp);

    long long upleft = matrix[i][j] + helper(i-1,j-1,matrix,dp);

    long long upright = matrix[i][j] + helper(i-1,j+1,matrix,dp);

    return dp[i][j]= min(up,min(upleft,upright));
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>dp(row,vector<int>(col,0));
        for(int j=0;j<col;j++){
            dp[0][j]=matrix[0][j];
        }

        for(int i=1;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                long long up = matrix[i][j] + dp[i-1][j];
                long long upleft = matrix[i][j];

                if(j>0)upleft+=dp[i-1][j-1];
                else upleft+=INT_MAX;

                long long upright=matrix[i][j];
                if(j+1<col) upright+=dp[i-1][j+1];
                else upright+=INT_MAX;
                
                dp[i][j] = min(up,min(upleft,upright));

            }
        }
        int mini=INT_MAX;
        for(int i=0;i<col;i++)
        {
            mini=min(mini,dp[row-1][i]);
        }
        return mini;
    }
};