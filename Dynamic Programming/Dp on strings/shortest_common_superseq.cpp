#include<bits/stdc++.h>
using namespace std;

void lcs(string s,string t)
{
    int n=s.size();
    int m =t.size();
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
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<"Length of LCS: "<<dp[n][m]<<endl;
    cout<<"Length of shortest common supersequence: "<<n+m-dp[n][m]<<endl;//as we remove lcs and add the uncommon part os both strings
    //eg - > str1 = brute
    //str2 = groot
    //lcs = rt
    //remove 'rt' and add 'bue' and 'goo' and then add 'rt' again to include it only once

    

}
class Solution {
public:
    void lcs2(string str1,string str2,vector<vector<int>>&dp)
    {
        int n = str1.size();
        int m = str2.size();

        for(int i=0;i<=n;i++)
        dp[i][0]=0;
        for(int j=0;j<=m;j++)
        dp[0][j]= 0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1]==str2[j-1])
                dp[i][j]= 1 + dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

            }
        }


    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        lcs2(str1,str2,dp);
        string ans="";
        int i=n;int j=m;
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
            ans+=str1[i-1];
            i--;j--;
            }

            else if(dp[i-1][j]>dp[i][j-1])
            {
            ans+=str1[i-1];
            i--;
            }
            else
            {
                ans+=str2[j-1];
                j--;
            }

        }
        while(i>0)
        {
            ans+=str1[i-1];
            i--;
        }
        while(j>0)
        {
            ans+=str2[j-1];
            j--;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    string s = "brute";
    string t="groot";
    lcs(s,t);



}