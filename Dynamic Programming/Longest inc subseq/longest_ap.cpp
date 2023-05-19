#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(1001,1));//LIS pattern 
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                int diff = nums[i]-nums[prev]+500;
                dp[i][diff] = max(dp[i][diff],1+dp[prev][diff]);

                ans = max(ans,dp[i][diff]);
            }
        }
        return ans;

    }
};