#include<bits/stdc++.h>
using namespace std;
//house robber
int helper(int index,vector<int>nums,vector<int>&dp)
{
    if(index==0)
    return nums[index];

    if(index<0)return 0;

    if(dp[index]!=-1)return dp[index]; //memoization 
    int pick = helper(index-2,nums,dp) + nums[index];
    int notpick=helper(index-1,nums,dp) + 0;

    return dp[index] = max(pick,notpick);
}
int main()
{
    vector<int> nums={1,2,3,1};

    int n=nums.size();
    vector<int>dp(n,-1);
    cout<<helper(nums.size()-1,nums,dp);
}


