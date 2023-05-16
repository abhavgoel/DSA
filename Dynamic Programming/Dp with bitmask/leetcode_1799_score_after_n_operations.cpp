#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int helper(vector<int>&nums,vector<int>&vis,int op , map<vector<int>,int>&mp,int n)
    // {
    //     if(op>n/2)return 0;
    //     if(mp[vis]!=0)
    //     return mp[vis];
    //     int maxi = 0;

    //     for(int i=0;i<n-1;i++)//genrating all pairs
    //     {
    //         if(vis[i]==1)
    //         continue;

    //         for(int j=i+1;j<n;j++)
    //         {
    //             if(vis[j]==1)
    //             continue;

    //             vis[i]=1;
    //             vis[j]=1;

    //             int score = op *__gcd(nums[i],nums[j]) + helper(nums,vis,op+1,mp,n);

    //             vis[i]=0;//backtracking
    //             vis[j]=0;

    //             maxi = max(maxi,score);
    //         }
    //     }
    //     return mp[vis] = maxi;
    // }

    int helper(vector<int>& nums, int op, int mask, vector<int>& dp){
        int m = nums.size(), n = nums.size()/2;
        if(op > n) return 0;
        if(dp[mask] != -1) return dp[mask];

        for(int i=0;i<m-1;i++)
        {
            if(mask & (1<<i))
            continue;
            for(int j=i+1;j<m;j++)
            {
                if(mask & (1<<j))
                continue;
                
                int newMask = (1<<i) | (1<<j) | mask;
                int score = op * __gcd(nums[i],nums[j]) + helper(nums, op+1, newMask, dp);
                dp[mask] = max(dp[mask], score);
            }
        }
        return dp[mask];
    }

    int maxScore(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(1<<14,-1);

        return helper(nums,1,0,dp);
        // vector<int>vis(n,0);
        // map<vector<int>,int>mp;

        // return helper(nums,vis,1,mp,n);
        
    }
};