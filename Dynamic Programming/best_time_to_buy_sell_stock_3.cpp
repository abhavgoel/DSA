#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int helper(int i,int buy,int limit,vector<int>&prices,vector<vector<vector<int>>>&dp)
{
    if(limit==0)
    return 0;
    if(i==prices.size())
    return 0;

    if(dp[i][buy][limit]!=-1)return dp[i][buy][limit];
    long long profit=0;

    if(buy==1)
    {
        profit= max(-prices[i] + helper(i+1,0,limit,prices,dp),
        0+helper(i+1,1,limit,prices,dp));

    }
    else
    {
        profit=max(prices[i]+helper(i+1,1,limit-1,prices,dp),
        0+helper(i+1,0,limit,prices,dp));
    }
    return dp[i][buy][limit]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // return helper(0,1,2,prices,dp);
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int i=0;i<=n;i++)
        {
            for(int buy=0;buy<=1;buy++)
            dp[i][buy][0]=0;
        }
        for(int buy=0;buy<=1;buy++)
        {
            for(int limit=0;limit<=2;limit++)
            dp[n][buy][limit]=0;
        }

        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int limit=1;limit<=2;limit++)
                {
                    long long profit=0;

                    if(buy==1)
                    {
                        profit= max(-prices[i] + dp[i+1][0][limit],
                        0+dp[i+1][1][limit]);

                    }
                    else
                    {
                        profit=max(prices[i]+dp[i+1][1][limit-1],
                        0+dp[i+1][0][limit]);
                    }
                    dp[i][buy][limit]=profit;
                }
            }
        }
        return dp[0][1][2];
        
    }
};