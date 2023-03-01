#include<bits/stdc++.h>
using namespace std;
// same as partition into susets with given difference

class Solution {
public:
int helper(int index,int target,vector<int>nums,vector<vector<int>>&dp)
{
    if(index==0)
    {
        if(target==0&&nums[0]==0)return 2;
        else if(nums[0]==target || target==0)return 1;
        else return 0;
    }
    if(dp[index][target]!=-1)return dp[index][target];
    int notpick = helper(index-1,target,nums,dp);
    int pick = 0;
    if(nums[index]<=target)
    pick = helper(index-1,target-nums[index],nums,dp);

    return dp[index][target] =  pick+notpick;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        //we need to find subsets with given difference
        //s1-s2=d
        //totalsum-s2-s2=d
        //(totalsum-d)/2 = s2
       

        int sum=0;
        for(int i:nums)sum+=i;

        if(sum-target<0)return 0;
        if((sum-target)%2!=0)return 0;

        int s2=(sum-target)/2;
         vector<vector<int>>dp(nums.size(),vector<int>(s2+1,-1));

        return helper(nums.size()-1,s2,nums,dp);
        
    }
};