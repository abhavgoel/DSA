#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
bool isPalindrome(int i,int j,string &s)
{
    while(i<j)
    {
    if(s[i]!=s[j])return false;
    i++;j--;
    
    
    }

    return true;
}
int helper(int i,int j , string &s,vector<int>&dp)
{
   
    if(i==j || isPalindrome(i,j,s))//if the given striing itself is palindrome , 
    //it cant be partioned to make a palindrome 
    return 0;
    if(dp[i]!=-1)return dp[i];
    int ans=INT_MAX;//max partition can be string length -1
    for(int ind=i;ind<j;ind++)
    {
       
        if(isPalindrome(i,ind,s))
        {
        int partition = 1+helper(ind+1,j,s,dp);cout<<partition<<endl;
        ans=min(ans,partition);
        }

    }
    return dp[i] = ans;
}
    int minCut(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        return helper(0,n-1,s,dp);
    }
};