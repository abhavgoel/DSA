#include <bits/stdc++.h> 
using namespace std;

//approach 1
int helper(int i,int j,string s,string t,vector<vector<int>>&dp)
{
    if(i==0)return j;
    if(j==0)return  i;
   
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(s[i-1]==t[j-1])
    return 0 + helper(i-1,j-1,s,t,dp);
    

    int del = 1 + helper(i-1,j,s,t,dp);
    
    int insert = 1 + helper(i,j-1,s,t,dp);

    return  dp[i][j]= min(del,insert);
}
int canYouMake(string &str, string &ptr)
{
    int n=str.size();
    int m=ptr.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return helper(str.size(),ptr.size(),str,ptr,dp);
}

//approach 2 by LCS

int lcs(string s ,string t)
{
    int n = s.size();
    int m = t.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<=n;i++)
    dp[i][0]=0;
    for(int j=0;j<=m;j++)
    dp[0][j]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            dp[i][j]= 1 + dp[i-1][j-1];

            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return n+m -2*dp[n][m]; // n-lcs deletions then m-lcs insertions then add
}
