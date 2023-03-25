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
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(0,-1,nums,dp);
    }
};