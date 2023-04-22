#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //attaching the reversed version of the string would make it palindrome
    //so any string can be made into a plaindrome
    //max length to make palindrome  = length of string itself
    int minInsertions(string s) {
        string t = s;
        reverse(s.begin(),s.end());
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        //we find longest palindromic subseq and subtract it from the length of string

        for(int i=0,j=0;i<=n,j<=n;i++,j++)
        {
        dp[i][0]=0;
        dp[0][j]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
                else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return n-dp[n][n];
    }
};