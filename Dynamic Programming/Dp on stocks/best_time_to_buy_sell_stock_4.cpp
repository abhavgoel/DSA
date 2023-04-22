#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int helper(int i,int transactions,int k,vector<int>prices,vector<vector<int>>&dp)
{
    /*transactions = Buy Sell Buy Sell 
                      0    1   2    3

    */

    if(transactions==2*k)
    return 0;

    if(i==prices.size())
    return 0;

    if(dp[i][transactions]!=-1)return dp[i]
[transactions];    
    long long profit=0;
    if(transactions%2==0)//buy condition
    {
        profit=max(-prices[i]+helper(i+1,transactions+1,k,prices,dp),
        0+helper(i+1,transactions,k,prices,dp));
    }
    else
    {
        profit=max(prices[i]+helper(i+1,transactions+1,k,prices,dp),
        0+helper(i+1,transactions,k,prices,dp));
    }
    return dp[i][transactions] = profit;

}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2*k,-1));
        // return helper(0,0,k,prices,dp);

        vector<vector<int>>dp(n+1,vector<int>((2*k)+1,-1));

            for(int i=0;i<=n;i++)
            dp[i][2*k]=0;
            for(int transactions=0;transactions<=2*k;transactions++)
            dp[n][transactions]=0;

            for(int i=n-1;i>=0;i--)
            {
                for(int transactions=0;transactions<2*k;transactions++)
                {
                        long long profit=0;
                        if(transactions%2==0)//buy condition
                        {
                            profit=max(-prices[i]+dp[i+1][transactions+1],
                            0+dp[i+1][transactions]);
                        }
                        else
                        {
                            profit=max(prices[i]+dp[i+1][transactions+1],
                            0+dp[i+1][transactions]);
                        }
                        dp[i][transactions]=profit;
                }
            }
            return dp[0][0];
    }
};