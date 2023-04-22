#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int helper(int i,int j,string text1,string text2,vector<vector<int>>&dp)
{
    if(i<0||j<0)
    return 0;

    if(dp[i][j]!=-1)return dp[i][j];
    if(text1[i]==text2[j])
    return dp[i][j] =  1 + helper(i-1,j-1,text1,text2,dp);

    return dp[i][j] =  0 + max(helper(i-1,j,text1,text2,dp),helper(i,j-1,text1,text2,dp));//both possibilities of both strings

    //for eg
    /*
    str1->ec
    str2->ce

    then we have to check for both strings when we go back

    case 1 -> i-1,j --> e of str1 matches with e of str2
    case 2-> i,j-1 --> c of str2 matches with c of str1

    */
}
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m=text2.size();
        // vector<vector<int>>dp(i,vector<int>(j,-1));

        // return helper(n-1,m-1,text1,text2,dp);

         vector<vector<int>>dp(n,vector<int>(m,0));

         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                if(text1[i]==text2[j])
                {
                if(i-1>=0 && j-1>=0)
                dp[i][j] =  1 + helper(i-1,j-1,text1,text2,dp);
                else dp[i][j]=1;
                }
                else 
                {
                    dp[i][j]=0;
                    int a=0,b=0;
                    if(i-1>=0)
                    a=dp[i-1][j];
                    if(j-1>=0)
                    b=dp[i][j-1];

                    dp[i][j]=max(a,b);

                }
             }
         }
         return dp[n-1][m-1];
    }
};