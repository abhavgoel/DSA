#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
int helper(int index,int target,vector<int>profit,vector<int>weight,vector<vector<int>>&dp)
{
    if(index==0)
    {
        return (target/weight[0]) * profit[0];
    }
    if(dp[index][target]!=-1)return dp[index][target];

    int notpick = 0+helper(index-1,target,profit,weight,dp);
    int pick =INT_MIN;
    if(weight[index]<=target)
    pick = profit[index] + helper(index,target-weight[index],profit,weight,dp);

    return dp[index][target] =  max(pick,notpick);

}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // vector<vector<int>>dp(n,vector<int>(w+1,-1));
    
    // return helper(n-1,w,profit,weight,dp);

    vector<vector<int>>dp(n,vector<int>(w+1,0));

    for(int t=0;t<=w;t++)
        dp[0][t] = (t/weight[0]) *profit[0];

    for(int i=1;i<n;i++)
    {
        for(int t=0;t<=w;t++)
        {
            int notpick = 0+dp[i-1][t];
            int pick =INT_MIN;
            if(weight[i]<=t)
            pick = profit[i] + dp[i][t-weight[i]];

            dp[i][t] =  max(pick,notpick);
        }
    }
    return dp[n-1][w];
    



}
