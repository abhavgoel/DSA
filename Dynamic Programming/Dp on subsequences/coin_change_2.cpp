#include<bits/stdc++.h>
using namespace std;
//number of ways in which target can be reached by coins denominations
class Solution {
public:
int helper(int index,int target,vector<int>coins,vector<vector<int>>&dp)
{
    if(index==0)
    {
        return (target%coins[0]==0);
    }
    if(dp[index][target]!=-1)return dp[index][target];

    int notpick = helper(index-1,target,coins,dp);

    int pick = 0;
    if(coins[index]<=target)
    pick = helper(index,target-coins[index],coins,dp);

    return dp[index][target] =  pick + notpick;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));

        // return helper(coins.size()-1,amount,coins,dp);
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));

        for(int t=0;t<=amount;t++)
        {
            if(t%coins[0]==0)dp[0][t]=1;
            else dp[0][t]=0;

        }

        for(int i=1;i<n;i++)
        {
            for(int t=0;t<=amount;t++)
            {
                int notpick = dp[i-1][t];

                int pick = 0;
                if(coins[i]<=t)
                pick = dp[i][t-coins[i]];

                dp[i][t] =  pick + notpick;
            }
        }
        return dp[n-1][amount];
    }
};