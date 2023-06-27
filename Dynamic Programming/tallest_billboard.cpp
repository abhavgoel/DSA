#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//----------brute force---------------------
    // int helper(int i,int len1,int len2,vector<int>&rods)
    // {
    //     if(i>=rods.size())
    //     {
    //         if(len1==len2)
    //         return len1;

    //         return 0;
    //     }
       

    //     int notpick = helper(i+1,len1,len2,rods);
    //     int pick1 = helper(i+1,len1+rods[i],len2,rods);
    //     int pick2 = helper(i+1,len1,len2+rods[i],rods);

    //     return max({notpick,pick1,pick2});
    // }
    int helper(int i,int diff,vector<int>&rods,vector<vector<int>>&dp)
    {
        if(i>=rods.size())
        {
            if(diff==0)
            {
                return 0;
            }

            return INT_MIN;
        }
        if(dp[i][diff+5000]!=-1)return dp[i][diff+5000];
        
        int notpick = helper(i+1,diff,rods,dp);
        int pick1 = rods[i] + helper(i+1 , diff + rods[i],rods,dp);
        int pick2= rods[i] + helper(i+1,diff-rods[i],rods,dp);

        return dp[i][diff+5000] = max({notpick,pick1,pick2});
    }
    int tallestBillboard(vector<int>& rods) {
        vector<vector<int>>dp(rods.size(),vector<int>(10001,-1));
        return helper(0,0,rods,dp)/2;
    }
};