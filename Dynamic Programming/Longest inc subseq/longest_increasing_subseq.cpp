#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int helper(int i,int prev,vector<int>&nums,vector<vector<int>>&dp)
{
    if(i==nums.size())
    return 0;

    if(dp[i][prev+1]!=-1)return dp[i][prev+1];//to handle the index=-1 case

    int notpick = 0 + helper(i+1,prev,nums,dp);
    int pick=-1;
    if(prev==-1 || nums[i]>nums[prev])
    pick=1 + helper(i+1,i,nums,dp);//picked i now i is the prev index for next call

    return dp[i][prev+1] = max(pick,notpick);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return helper(0,-1,nums,dp);

        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int prev=0;prev<=n;prev++)
        dp[0][prev]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=i-1;prev>=-1;prev--)
            {
                int notpick = 0 + dp[i+1][prev+1];
                int pick=-1;
                if(prev==-1 || nums[i]>nums[prev])
                pick=1 + dp[i+1][i+1];

                dp[i][prev+1]=max(pick,notpick);

               
            }
            
        }
        return dp[0][-1+1];
    }
    
};

//aproach 2

  int lengthOfLIS(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>dp(n,1);
        
        for(int i=0;i<n;i++)
        {
            
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]>nums[prev])
                dp[i]=max(dp[i],1+dp[prev]);
            }

        }
        return *max_element(dp.begin(),dp.end());
    }
