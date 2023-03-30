#include<bits/stdc++.h>
using namespace std;

int helper(int i,int j,vector<int>&arr,int N,vector<vector<int>>&dp)
{
    if(i==j)
    return 0;//matrix multiplication operations of a single matrix is 0

    if(dp[i][j]!=-1)return dp[i][j];

    int ans=1e9;
    for(int k=i;k<j;k++)
    {
        int steps = arr[i-1]*arr[k]*arr[j] + helper(i,k,arr,N,dp) + helper(k+1,j,arr,N,dp);
        ans=min(ans,steps);

    }
    return dp[i][j] =  ans;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // vector<vector<int>>dp(N,vector<int>(N,-1));

    // return helper(1,N-1,arr,N,dp);

    vector<vector<int>>dp(N,vector<int>(N,0));

    for(int i=1;i<N;i++)
    dp[i][i]=0;

    for(int i=N-1;i>=1;i--)//i from 1 to N-1
    {
        for(int j=i+1;j<N;j++)// j will be always ahea of i... so j=i+1
        {
            int ans=1e9;
            for(int k=i;k<j;k++)
            {
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                ans=min(ans,steps);

            }
            dp[i][j] =  ans;
        }
    }
    return dp[1][N-1];

}