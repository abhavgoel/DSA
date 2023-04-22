#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int helper(int i,int buy,int fee,vector<int>&prices,vector<vector<int>>&dp)
{
    if(i==prices.size())
    return 0;

    long long profit=0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    if(buy==1)
    {
        profit=max(-prices[i]+helper(i+1,0,fee,prices,dp),
        0+helper(i+1,1,fee,prices,dp));
    }
    else
    {
        profit=max(prices[i]+helper(i+1,1,fee,prices,dp)-fee,
        0+helper(i+1,0,fee,prices,dp));
    }
    return dp[i][buy] = profit;
}
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return helper(0,1,fee,prices,dp);
        vector<vector<int>>dp(n+1,vector<int>(2,0));

         for(int i=n-1;i>=0;i--)
         {
             for(int buy=0;buy<=1;buy++)
             {
                long long profit=0;
                if(buy==1)
                {
                    profit= max(-prices[i] + dp[i+1][0],
                    0+dp[i+1][1]);

                }
                else
                {
                    profit=max(prices[i]+dp[i+1][1]-fee,
                    0+dp[i+1][0]);
                }
                dp[i][buy]=profit;
             }
         }
         return dp[0][1];
    }
};