#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dfs(int i, vector<int> &nums, vector<int> &dp,unordered_map<int,int>&mp) {
        if(i == nums.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int notpick = 0 + dfs(i + 1, nums, dp,mp);
        int pick = mp[nums[i]]*nums[i];
       
        if(i + 1 < nums.size() && nums[i] + 1 == nums[i + 1]) pick += dfs(i + 2, nums, dp,mp);
        else if(i + 1 < nums.size() && nums[i] + 1 != nums[i + 1]) pick += dfs(i + 1, nums, dp,mp);
        
        return dp[i] = max(pick, notpick);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        
        
        int n = nums.size();
        vector<int> dp(n, -1);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<int>dupnums;
        for(auto i:mp)
        dupnums.push_back(i.first);

        sort(dupnums.begin(), dupnums.end());


        return dfs(0, dupnums, dp,mp);
    }
};