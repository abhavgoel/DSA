#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
int helper(int i, int j , string s,string t,vector<vector<int>>&dp)
{
    if(j==0)
    return 1;// no subseq of string 2 left to match i.e we found a subseq

    if(i==0)
    return 0; // no string left to count subseq

    if(dp[i][j]!=-1)return dp[i][j];
    
    if(s[i-1]==t[j-1])
    return  dp[i][j] = helper(i-1,j-1,s,t,dp) + helper(i-1,j,s,t,dp);
    else
    return  dp[i][j] = helper(i-1,j,s,t,dp);
    
}
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return helper(n,m,s,t,dp);

        vector<vector<double>>dp(n+1,vector<double>(m+1,0));//prevent integer overflow

        for(int i=0;i<=n;i++)
        dp[i][0]=1;
        for(int j=1;j<=m;j++)//as j=0 we return 1 and if the loop start from 0 it will rewrite it to 0
        dp[0][j]=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return (int)dp[n][m];//prevent integer overflow


    }
};