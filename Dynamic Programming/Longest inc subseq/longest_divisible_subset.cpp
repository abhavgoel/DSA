#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lengthOfLIS(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>dp(n,1),hash(n,0);
        int maxi=-1;
        int lastindex=0;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]%nums[prev]==0 && dp[i]<1+dp[prev])
                {
                    dp[i]=1+dp[prev];
                    hash[i]=prev;

                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                lastindex=i;
            }
           
        }
            vector<int>ans;
            ans.push_back(nums[lastindex]);
            while(hash[lastindex]!=lastindex)
            {
                lastindex=hash[lastindex];
                ans.push_back(nums[lastindex]);
            }
            reverse(ans.begin(),ans.end());
        //cout<<maxi;
        return ans;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {//longest divisible subseq
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return lengthOfLIS(nums);
        


    }
};