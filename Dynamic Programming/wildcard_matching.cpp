#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int helper(int i,int j,string str,string pattern,vector<vector<int>>&dp)
{

    if(i==0&&j==0)return true;
    if(j==0 && i>0)return false;//pattern exahusted but string left to match
    if(i==0&&j>0)//string exhausted but pattern left to match, only true if all pattern is "*"
    {
        for(int k=1;k<=j;k++)
        {
            if(pattern[k-1]!='*')
            return false;
        }
    return true;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(str[i-1]==pattern[j-1] || pattern[j-1]=='?')
    return dp[i][j] = helper(i-1,j-1,str,pattern,dp);

    if(pattern[j-1]=='*')
    return dp[i][j] = helper(i-1,j,str,pattern,dp)|helper(i,j-1,str,pattern,dp);

    return dp[i][j] = false;
}
    bool isMatch(string str, string pattern) {
        int n=str.size();
        int m=pattern.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return helper(n,m,str,pattern,dp);
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        dp[0][0]=true;
        for(int i=1;i<=n;i++)
        dp[i][0]=false;

        for(int j=1;j<=m;j++)
        {
            bool flag=true;
            for(int k=1;k<=j;k++)
            {
                if(pattern[k-1]!='*')
                {
                flag=false;
                break;
                }
            }
            dp[0][j]=flag;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str[i-1]==pattern[j-1] || pattern[j-1]=='?')
                dp[i][j] = dp[i-1][j-1];

                else if(pattern[j-1]=='*')
                dp[i][j] = dp[i-1][j]|dp[i][j-1];

                else
                dp[i][j]=false;
            }
        }
        return dp[n][m];




        
    }
};