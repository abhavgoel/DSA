#include <bits/stdc++.h> 
using namespace std;
//handles 0 in array cases


int helper(int index,int target,vector<int>num,vector<vector<int>>&dp)
{
    //if(target==0)return 1;
    if(index==0)
    {
        if(target==0&&num[0]==0)return 2;
        else if(num[0]==target || target==0)return 1;
        return 0;
    }
    if(dp[index][target]!=-1)return dp[index][target];
    int notpick = helper(index-1,target,num,dp);

    int pick = 0;
    if(num[index]<=target)
    pick = helper(index-1,target-num[index],num,dp);

    return dp[index][target]=  pick + notpick;
}
int findWays(vector<int> &num, int tar)
{
    vector<vector<int>>dp(num.size(),vector<int>(tar+1,0));
    //return helper(num.size()-1,tar,num,dp);

    for(int i=0;i<num.size();i++)
    dp[i][0]=1;
    if(num[0]<=tar)
    dp[0][num[0]]=1;

    if(num[0]==0)
    dp[0][0]=2;


    

    for(int i=1;i<num.size();i++)
    {
        for(int j=0;j<=tar;j++)
        {
            int notpick = dp[i-1][j];
            int pick = 0;
            if(num[i]<=j)pick = dp[i-1][j-num[i]];
            dp[i][j] = pick+notpick;
        }
    }
    return dp[num.size()-1][tar];
}