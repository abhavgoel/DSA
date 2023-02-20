#include <bits/stdc++.h> 
using namespace std;
bool helper(int index,int target,vector<int> &arr,vector<vector<int>>&dp)
{
    if(target==0)return true;

    if(index==0)return arr[0]==target;

    if(dp[index][target]!=-1)return dp[index][target];
    bool notpick = helper(index-1,target,arr,dp);
    bool pick = false;

    if(arr[index]<=target)
    pick =helper(index-1,target-arr[index],arr,dp);

    return dp[index][target] =  pick|notpick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>>dp(n , vector<bool>(k+1,0));
   

    //return helper(arr.size()-1,k,arr,dp);

    for(int i=0;i<n;i++)
    {
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;

    for(int index=1;index<n;index++)
    {
        for(int target=1;target<=k;target++)
        {
             bool notpick = dp[index-1][target];
            bool pick = false;

            if(arr[index]<=target)
            pick =dp[index-1][target-arr[index]];

             dp[index][target] =  pick|notpick;
        }

    }
    return dp[n-1][k];
}