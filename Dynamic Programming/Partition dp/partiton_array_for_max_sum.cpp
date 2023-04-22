#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int helper(int i,int n,vector<int>&arr,int k,vector<int>&dp )
{
    if(i==n)return 0;
    if(dp[i]!=-1)return dp[i];
    int len = 0;
    int arrmax=INT_MIN;
    int maxans = INT_MIN;
    for(int j = i;j<min(n,i+k);j++)
    {
        len++;
        arrmax=max(arrmax,arr[j]);
        int sum  = len*arrmax + helper(j+1,n,arr,k,dp);
        maxans = max(maxans,sum);


    }
    return dp[i] = maxans;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // vector<int>dp(n,-1);
        // return helper(0,n,arr,k,dp);

        vector<int>dp(n+1,0);
        dp[n] = 0;

        for(int i=n-1;i>=0;i--)
        {
            int len = 0;
            int arrmax=INT_MIN;
            int maxans = INT_MIN;
            for(int j = i;j<min(n,i+k);j++)
            {
                len++;
                arrmax=max(arrmax,arr[j]);
                int sum  = len*arrmax + helper(j+1,n,arr,k,dp);
                maxans = max(maxans,sum);


            }
            dp[i] = maxans;
        }
        return dp[0];
        
    }
};