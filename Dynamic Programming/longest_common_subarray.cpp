#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int helper(int i,int j,vector<int>nums1,vector<int>nums2,int count,vector<vector<vector<int>>>&dp)
{
    if(i==0 || j==0)
    return count;

    if (dp[i][j][count] != -1)
        return dp[i][j][count];

    int same=count;


    if(nums1[i-1]==nums2[j-1])
    same = helper(i-1,j-1,nums1,nums2,count+1,dp);

    same = max(same,max(helper(i-1,j,nums1,nums2,0,dp),helper(i,j-1,nums1,nums2,0,dp)));
    dp[i][j][count] = same;
    return same;
    
}
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(n+m+1,-1)));

        // return helper(n,m,nums1,nums2,0,dp);

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int j=0;j<=m;j++)dp[0][j]=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                dp[i][j]=1+dp[i-1][j-1];

                else
                {
                    dp[i][j]=0;
                }
            }
        }
        int ans=-1;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                ans=max(ans,dp[i][j]);
            }
        }

        return ans;

    }
};