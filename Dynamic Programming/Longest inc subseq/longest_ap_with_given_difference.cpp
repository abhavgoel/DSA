#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//dp memoization--------------------------------------------------------
int helper(int i,int prev,vector<int>&nums,int diff,vector<vector<int>>&dp)
{
    if(i==nums.size())
    return 0;

    if(dp[i][prev+1]!=-1)return dp[i][prev+1];
    int notpick = 0 + helper(i+1,prev,nums,diff,dp);
    int pick = -1;
    if(prev==-1 || nums[i]-nums[prev]==diff)
    pick = 1 + helper(i+1,i,nums,diff,dp);

    return dp[i][prev+1] = max(pick,notpick);
}
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return helper(0,-1,arr,difference,dp);
        unordered_map<int,int>mp;
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int diff = arr[i] - difference;

            if(mp.count(diff)>0)
            mp[arr[i]] = mp[diff] + 1;
            else mp[arr[i]]=1;

            ans = max(ans,mp[arr[i]]);

        }
        return ans;
    }
};