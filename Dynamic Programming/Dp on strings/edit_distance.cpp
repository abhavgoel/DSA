#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int helper(int i,int j,string word1, string word2, vector<vector<int>>&dp)
{
    if(i==0)return j;//insert on empty string1 to convert it to string 2
    if(j==0)return  i;//delete from string 1 to convert it to string 2

    if(dp[i][j]!=-1)return dp[i][j];
    
    if(word1[i-1]==word2[j-1])
    return 0 + helper(i-1,j-1,word1,word2,dp);
    


    

    int del = 1 + helper(i-1,j,word1,word2,dp);
    /*
    str1 = horse --> i pointer at 'e', then after we delete we move i by 1 and j remains same.
    str2 = ros
    */

    int insert = 1 + helper(i,j-1,word1,word2,dp);

    /*
     str1 = horse --> i pointer at 'e', if we insert 's' after 'e' then str1->horses, then we 
     move j pointer by 1 and i remains same bcoz we are hypothetically adding a character 
     after it which would match the j pointer.

    str2 = ros

    */

    int replace = 1 + helper(i-1,j-1,word1,word2,dp);
    /*
    str1 = horse --> i pointer at e , if we replace it with j of str2 then str1->horss
    then we move both pointer by 1.
    */

    return dp[i][j] =  min(del,min(insert,replace));
}
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        //vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        //return helper(m,n,word1,word2,dp);

         vector<vector<int>>dp(m+1,vector<int>(n+1,0));

         for(int i=0;i<=m;i++)dp[i][0]=i;
         for(int j=0;j<=n;j++)dp[0][j]=j;

         for(int i=1;i<=m;i++)
         {
             for(int j=1;j<=n;j++)
             {
                 if(word1[i-1]==word2[j-1])
                dp[i][j]=dp[i-1][j-1];
                
                else
                {
                int del = 1 + dp[i-1][j];

                int insert = 1 + dp[i][j-1];

                int replace = 1 + dp[i-1][j-1];
                

                dp[i][j]=min(del,min(insert,replace));
                }


             }
         }
         return dp[m][n];
    }
};