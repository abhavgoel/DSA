#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int helper(int index,vector<int>cost,vector<int>&dp)
{
    if(index<0)
    return 0;
    if(index==0)
    {
        return cost[0];
    }
    if(dp[index]!=-1)return dp[index];
    int l = cost[index] + helper(index-1,cost,dp);
    int r=cost[index] + helper(index-2,cost,dp);

    return dp[index] =  min(l,r);
    


}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,0);
        // return min(helper(n-1,cost,dp),helper(n-2,cost,dp));

        dp[0]=cost[0];

        for(int i=1;i<n;i++)
        {
            int l = cost[i] + dp[i-1];
            int r=cost[i];
            if(i>1)
           r+= dp[i-2];

           dp[i]=min(l,r);
        }
        return min(dp[n-1],dp[n-2]);
    }
};