#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
bool helper(int i , int j,string &s,string &p,vector<vector<int>>&dp)
{
    if(i==0 && j==0 )return true;//both string and pattern exhausted

    if(i>0 && j==0)return false;// string left but pattern exhausted

    if(i==0 && j>0)
    {
        if(p[j-1]=='*')
        {
            return helper(i,j-2,s,p,dp);
        }
        else return false;
    }

    if(dp[i][j]!=-1)return dp[i][j];

    if(s[i-1]==p[j-1] || p[j-1]=='.')//if the character matches 
    return dp[i][j] = helper(i-1,j-1,s,p,dp);

    if(p[j-1]=='*')
    {
        if(s[i-1]==p[j-2] || p[j-2]=='.')//if previous character matches
        return dp[i][j] = helper(i-1,j,s,p,dp) | helper(i,j-2,s,p,dp) ;//match now or match further
        else return dp[i][j] = helper(i,j-2,s,p,dp);//else reduce the pattern to match further

    }
    return dp[i][j] = false;
    

}
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        // return helper(n,m,s,p,dp);
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        dp[i][0]=0;

        for(int j=1;j<=m;j++)
        {
            if(p[j-1]=='*')
            {
                if(j-2>=0)
                dp[0][j]=dp[0][j-2];
            }
            else dp[0][j]=false;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='.')//if the character matches 
                dp[i][j] = dp[i-1][j-1];

                else if(p[j-1]=='*')
                {
                    if(j-2>=0)
                    {
                    if(s[i-1]==p[j-2] || p[j-2]=='.')//if previous character matches
                    dp[i][j] = dp[i-1][j] | dp[i][j-2] ;//match now or match further

                    else dp[i][j] = dp[i][j-2];//else reduce the pattern 
                    //to match further
                    }

                }
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};