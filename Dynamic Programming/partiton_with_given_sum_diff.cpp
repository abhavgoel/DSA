#include <bits/stdc++.h> 
using namespace std;

//into two subsets

//s1-s2=d
//totalsum-s2-s2=d
//(totalsum-d)/2 = s2

int mod=1e9+7;
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum = 0;
    for(int i:arr)sum+=i;

    if(sum-d<0)return 0;//coudlnt be negative
    if((sum-d)%2!=0)return 0;//all number are int to sum couldnt be fraction

    int tar = (sum-d)/2;


    vector<vector<int>>dp(arr.size(),vector<int>(tar+1,0));
    //return helper(num.size()-1,tar,num,dp);

    for(int i=0;i<arr.size();i++)
    dp[i][0]=1;
    if(arr[0]<=tar)
    dp[0][arr[0]]=1;

    if(arr[0]==0)
    dp[0][0]=2;


    

    for(int i=1;i<arr.size();i++)
    {
        for(int j=0;j<=tar;j++)
        {
            int notpick = dp[i-1][j];
            int pick = 0;
            if(arr[i]<=j)pick = dp[i-1][j-arr[i]];
            dp[i][j] = (pick+notpick)%mod;
        }
    }
    return dp[arr.size()-1][tar];
}


