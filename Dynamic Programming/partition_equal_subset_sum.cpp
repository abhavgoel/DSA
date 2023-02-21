#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool helper(int index,int target,vector<int>arr)
{
    int n=arr.size();
    int k=target;
     vector<vector<bool>>dp(n , vector<bool>(k+1,0));
     for(int i=0;i<n;i++)
    {
        dp[i][0]=true;
    }
    if(arr[0]<=k)
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
    bool canPartition(vector<int>& nums) {
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)return false;

        sum=sum/2;
        // vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));

        return helper(0,sum,nums);




    }
};