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
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));

        return helper(coins.size()-1,amount,coins,dp);
    }
};