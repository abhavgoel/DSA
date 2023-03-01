#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int helper(int index,int amount,vector<int>&coins,vector<vector<int>>&dp)
{
    if(index==0)
    {
        if(amount%coins[0]==0)return (amount/coins[0]);
        else return 1e9;
    }
    if(dp[index][amount]!=-1)return dp[index][amount];
    int notpick = 0 + helper(index-1,amount,coins,dp);
    int pick= INT_MAX;
    if(coins[index]<=amount)
    pick = 1+helper(index,amount-coins[index],coins,dp);

    return dp[index][amount]=min(pick,notpick);
}
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
        // int ans= helper(coins.size()-1,amount,coins,dp);
        // if(ans==1e9)
        // return -1;
        // return ans;

        for(int t=0;t<=amount;t++)
        {
            if(t%coins[0]==0)dp[0][t] = t/coins[0];
            else dp[0][t] = 1e9;
        }

        for(int index=1;index<coins.size();index++)
        {
            for(int t=0;t<=amount;t++)
            {
                int notpick = 0 + dp[index-1][t];
                int pick= 1e9;
                if(coins[index]<=t)
                pick = 1+dp[index][t-coins[index]];
                dp[index][t]=min(pick,notpick);

            }
        }
        int ans= dp[coins.size()-1][amount];
        if(ans>=1e9)
        return -1;
        return ans;


    }
};