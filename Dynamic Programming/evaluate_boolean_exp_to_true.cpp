#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007;
int helper(int i,int j,int isTrue,string&exp, vector<vector<vector<int>>>&dp)
{
    if(i>j)return 0;

    if(i==j)
    {
        if(isTrue==1)
        return exp[i]=='T';
        else return exp[i]=='F';

        
    }
    if(dp[i][j][isTrue]!=-1)return dp[i]
[j][isTrue];
    ll ways = 0 ;

    for(int ind=i+1;ind<=j-1;ind=ind+2)
    {
        ll leftTrue = helper(i,ind-1,1,exp,dp);
        ll leftFalse = helper(i,ind-1,0,exp,dp);
        ll rightTrue = helper(ind+1,j,1,exp,dp);
        ll rightFalse = helper(ind+1,j,0,exp,dp);

        if(exp[ind]=='&')
        {
            if(isTrue==1)
            ways=(ways + (leftTrue*rightTrue)%mod)%mod;//& operator so both should be true to give true as a result
            else
            ways=(ways + (leftFalse*rightTrue)%mod + (leftTrue*rightFalse)%mod + (leftFalse*rightFalse)%mod)%mod;
        }

        else if(exp[ind]=='|')
        {
            if(isTrue==1)
            ways=(ways + (leftFalse*rightTrue)%mod + (leftTrue*rightFalse)%mod + (leftTrue*rightTrue)%mod)%mod;
            else
            ways=(ways + (leftFalse*rightFalse)%mod)%mod;
        }


        else if(exp[ind]=='^')
        //T^T=F,F^F=F,T^F=T,F^T=T
        {
            if(isTrue==1)
            ways= (ways + (leftTrue*rightFalse)%mod + (leftFalse*rightTrue)%mod)%mod;
            else
            ways = (ways + (leftTrue*rightTrue)%mod + (leftFalse*rightFalse)%mod)%mod;
        }

    }
    return dp[i][j][isTrue] =  ways;
}
int evaluateExp(string & exp) {
    int n=exp.length();
    // vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
    // return helper(0,n-1,1,exp,dp);
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,0)));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            for(int isTrue=0;isTrue<=1;isTrue++)
            {
                if(i==j)
                {
                    if(isTrue==1)
                    {
                        dp[i][j][isTrue] = exp[i]=='T';
                    }
                    else
                    dp[i][j][isTrue] = exp[i]=='F';
                }
                else
                {
                    ll ways = 0 ;

                    for(int ind=i+1;ind<=j-1;ind=ind+2)
                    {
                        ll leftTrue = dp[i][ind-1][1];
                        ll leftFalse = dp[i][ind-1][0];
                        ll rightTrue = dp[ind+1][j][1];
                        ll rightFalse = dp[ind+1][j][0];

                        if(exp[ind]=='&')
                        {
                            if(isTrue==1)
                            ways=(ways + (leftTrue*rightTrue)%mod)%mod;//& operator so both should be true to give true as a result
                            else
                            ways=(ways + (leftFalse*rightTrue)%mod + (leftTrue*rightFalse)%mod + (leftFalse*rightFalse)%mod)%mod;
                        }

                        else if(exp[ind]=='|')
                        {
                            if(isTrue==1)
                            ways=(ways + (leftFalse*rightTrue)%mod + (leftTrue*rightFalse)%mod + (leftTrue*rightTrue)%mod)%mod;
                            else
                            ways=(ways + (leftFalse*rightFalse)%mod)%mod;
                        }


                        else if(exp[ind]=='^')
                        //T^T=F,F^F=F,T^F=T,F^T=T
                        {
                            if(isTrue==1)
                            ways= (ways + (leftTrue*rightFalse)%mod + (leftFalse*rightTrue)%mod)%mod;
                            else
                            ways = (ways + (leftTrue*rightTrue)%mod + (leftFalse*rightFalse)%mod)%mod;
                        }

                    }
                    dp[i][j][isTrue] =  ways;
                }

            }
        }
    }
    return dp[0][n-1][1];//dp[0][n-1][0]for false

}