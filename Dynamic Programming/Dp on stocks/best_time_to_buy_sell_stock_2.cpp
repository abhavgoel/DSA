#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int helper(int i,int buy,vector<int>prices, vector<vector<int>>&dp)
{
    //buy=1;
    //sell=0;
    if(i==prices.size())
    return 0;

    if(dp[i][buy]!=-1)return dp[i][buy];

    int profit=0;
    if(buy==1)
    {
        profit= max(-prices[i] + helper(i+1,0,prices,dp),//bought and moved to next index to sell
        0+helper(i+1,1,prices,dp));//not bought, looking to buy on next index

    }
    else
    {
        profit=max(prices[i]+helper(i+1,1,prices,dp),//sold and moved to other index to buy again
        0+helper(i+1,0,prices,dp));//not sold....moved to another index to sell
    }
    return dp[i][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return helper(0,1,prices,dp);

         vector<vector<int>>dp(n+1,vector<int>(2,0));

         dp[n][0]=dp[n][1]=0;

         for(int i=n-1;i>=0;i--)
         {
             for(int buy=0;buy<=1;buy++)
             {
                int profit=0;
                if(buy==1)
                {
                    profit= max(-prices[i] + dp[i+1][0],//bought and moved to next index to sell
                    0+dp[i+1][1]);//not bought, looking to buy on next index

                }
                else
                {
                    profit=max(prices[i]+dp[i+1][1],//sold and moved to other index to buy again
                    0+dp[i+1][0]);//not sold....moved to another index to sell
                }
                dp[i][buy]=profit;
             }
         }
         return dp[0][1];
        
    }
};