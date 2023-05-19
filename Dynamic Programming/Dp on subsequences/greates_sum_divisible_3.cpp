#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int helper(int i,int rem ,vector<int>&nums,vector<vector<int>>&dp)
{
    if(i==nums.size())
    {
        if(rem==0)return 0;
        else return -1e9;
    }
    if(dp[i][rem]!=-1)return dp[i][rem];
    int notpick = 0 + helper(i+1,rem,nums,dp);
    int pick = 0;
    
    pick = nums[i] + helper(i+1,(rem+nums[i])%3,nums,dp);

    return dp[i][rem] = max(pick,notpick);

}
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return helper(0,0,nums,dp);

    }
};