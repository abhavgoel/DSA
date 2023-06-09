#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int>dx={0,0,1,-1};
vector<int>dy={1,-1,0,0};
int helper(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp)
{
    if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size())
    return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int maxi=0;
    for(int k=0;k<4;k++)
    {
        int r = i + dx[k];
        int c = j + dy[k];

        if(r>=0 && r<matrix.size() && c>=0 && c<matrix[0].size() && matrix[r][c]>matrix[i][j])
        {
            maxi = max(maxi,1+helper(r,c,matrix,dp));
        }

    }
    return dp[i][j] = maxi;


}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = -1e8;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans = max(ans,helper(i,j,matrix,dp));
            }
        }
        return ans+1;
    }
};