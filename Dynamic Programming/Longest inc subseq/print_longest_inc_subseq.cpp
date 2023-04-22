#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>dp(n,1),hash(n,1);
        int maxi=-1;
        int lastindex=0;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]>nums[prev] && 1+dp[prev]>dp[i])
                {
                dp[i]=max(dp[i],1+dp[prev]);
                hash[i]=prev;
                }
            }
            
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                lastindex=i;//index of max length of LIS
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
            for(auto i:ans)
            cout<<i<<" ";
            cout<<endl;

            return maxi;//length of lis

            
        
    }
    int main()
    {
        vector<int>nums={5,4,11,1,16,8};
        cout<<lengthOfLIS(nums);
    }