#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int helper(int i,int j,string s1,string s2,vector<vector<int>>&dp)
{
    if(i==0||j==0)
    return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    if(s1[i-1]==s2[j-1])
    return  dp[i][j] = 1 + helper(i-1,j-1,s1,s2,dp);

    else
    return dp[i][j] =  0 + max(helper(i-1,j,s1,s2,dp),helper(i,j-1,s1,s2,dp));
}
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        // return helper(n,n,s,t,dp);

        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int j=0;j<=n;j++)dp[0][j]=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
                else
                {
                    dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
        
    }
};