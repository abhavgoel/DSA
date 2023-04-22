#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// int helper(int i,int buy,int limit,vector<int>&prices,vector<vector<vector<int>>>&dp)
// {
//     if(limit==0)
//     return 0;
//     if(i==prices.size())
//     return 0;

//     if(dp[i][buy][limit]!=-1)return dp[i][buy][limit];
//     long long profit=0;

//     if(buy==1)
//     {
//         profit= max(-prices[i] + helper(i+1,0,limit,prices,dp),
//         0+helper(i+1,1,limit,prices,dp));

//     }
//     else
//     {
//         profit=max(prices[i]+helper(i+1,1,limit-1,prices,dp),
//         0+helper(i+1,0,limit,prices,dp));
//     }
//     return dp[i][buy][limit]=profit;
// }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
//         // return helper(0,1,2,prices,dp);
//         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

//         for(int i=0;i<=n;i++)
//         {
//             for(int buy=0;buy<=1;buy++)
//             dp[i][buy][0]=0;
//         }
//         for(int buy=0;buy<=1;buy++)
//         {
//             for(int limit=0;limit<=2;limit++)
//             dp[n][buy][limit]=0;
//         }

//         for(int i=n-1;i>=0;i--)
//         {
//             for(int buy=0;buy<=1;buy++)
//             {
//                 for(int limit=1;limit<=2;limit++)
//                 {
//                     long long profit=0;

//                     if(buy==1)
//                     {
//                         profit= max(-prices[i] + dp[i+1][0][limit],
//                         0+dp[i+1][1][limit]);

//                     }
//                     else
//                     {
//                         profit=max(prices[i]+dp[i+1][1][limit-1],
//                         0+dp[i+1][0][limit]);
//                     }
//                     dp[i][buy][limit]=profit;
//                 }
//             }
//         }
//         return dp[0][1][2];

//2d dp
int helper(int i,int transactions,vector<int>prices,vector<vector<int>>&dp)
{
    /*transactions = Buy Sell Buy Sell 
                      0    1   2    3

    */

    if(transactions==4)
    return 0;

    if(i==prices.size())
    return 0;

    if(dp[i][transactions]!=-1)return dp[i]
[transactions];    
    long long profit=0;
    if(transactions%2==0)//buy condition
    {
        profit=max(-prices[i]+helper(i+1,transactions+1,prices,dp),
        0+helper(i+1,transactions,prices,dp));
    }
    else
    {
        profit=max(prices[i]+helper(i+1,transactions+1,prices,dp),
        0+helper(i+1,transactions,prices,dp));
    }
    return dp[i][transactions] = profit;

}
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    // vector<vector<int>>dp(n+1,vector<int>(4,-1));
    // return helper(0,0,prices,dp);

    vector<vector<int>>dp(n+1,vector<int>(4+1,-1));

    for(int i=0;i<=n;i++)
    dp[i][4]=0;
    for(int transactions=0;transactions<=3;transactions++)
    dp[n][transactions]=0;

    for(int i=n-1;i>=0;i--)
    {
        for(int transactions=0;transactions<=3;transactions++)
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