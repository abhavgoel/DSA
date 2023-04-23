#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

#define mod 1000000007;

//standard front partition problem
int helper(int i,string &s, int k,vector<int>&dp)
{
    if(i==s.size())
    return 1;
    if(s[i]=='0')return 0;

    if(dp[i]!=-1)return dp[i];
    long long ans = 0;
    long long temp=0;

    for(int j=i;j<s.size();j++)
    {
        temp= 10*temp + (s[j]-'0'); 

        if(temp>k )break;

        ans = ans + helper(j+1,s,k,dp)%mod;
        ans = ans%mod;
    }
    return dp[i] = ans;
}
    int numberOfArrays(string s, int k) {
        int n = s.size();
        // vector<int>dp(n,-1);
        // return helper(0,s,k,dp);
        vector<int>dp(n+1,0);
        dp[n]=1;
       

        for(int i=n-1;i>=0;i--)

        {
            if(s[i]=='0')
            {
                dp[i]=0;
                continue;
            }
            long long ans = 0;
            long long temp=0;

            for(int j=i;j<s.size();j++)
            {
                
                temp= 10*temp + (s[j]-'0'); 

                if(temp>k)break;

                ans = ans + dp[j+1]%mod;
                ans = ans%mod;
            }
            dp[i] = ans;
        }
        return dp[0];

        
    }
};