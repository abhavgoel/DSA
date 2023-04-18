#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
class Solution {
public:
int helper(int i,int j,vector<string>&words,string &target,vector<vector<int>>&dp, vector<vector<int>>&freq)
{
    if(j==target.size())
    return 1;
    if(i==words[0].size())
    return 0;


    if(dp[i][j]!=-1)return dp[i][j];
    int notpick = helper(i+1,j,words,target,dp,freq)%mod;

    long long pick = 0; 

    // for(auto &w:words)
    // {
    //     if(w[i]==target[j])
    //     {
    //         pick = pick + helper(i+1,j+1,words,target,dp)%mod;
    //     }
    // }
    if(freq[i][target[j]-'a']>0)
    pick = freq[i][target[j]-'a']*(long long)helper(i+1,j+1,words,target,dp,freq);//ways to get target[j]*ways to get next element of target 

    return dp[i][j] = (notpick + pick)%mod;

}
    int numWays(vector<string>& words, string target) {
        int n = target.size();//j
        int m=words[0].size();//i
    vector<vector<int>>freq(m,vector<int>(26));

        for(auto w:words)
        
        {
            for(int i=0;i<m;i++)
            {
                freq[i][w[i]-'a']++;//bookmark
            }
        }
        vector<vector<int>>dp(words[0].size()+1,vector<int>(target.size()+1,-1));
        return helper(0,0,words,target,dp,freq);

        // for(int i=0;i<=m;i++)
        // dp[i][n]=1;
        // // for(int j=0;j<=n;j++)
        // // dp[m][j]=0;

        // for(int i=m-1;i>=0;i--)
        // {
        //     for(int j=n-1;j>=0;j--)
        //     {
        //         int notpick = dp[i+1][j]%mod;

        //         long long pick = 0; 
        //         if(freq[i][target[j]-'a']>0)
        //         pick = freq[i][target[j]-'a']*(long long)dp[i+1][j+1];

        //         dp[i][j] = (notpick + pick)%mod;
        //     }
        // }
        // return dp[0][0];

        
    }
};