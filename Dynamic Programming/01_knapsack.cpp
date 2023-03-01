#include<bits/stdc++.h>
using namespace std;

int helper(int index,int weight[],int values[],int W,vector<vector<int>>&dp)
    {
        if(index==0)
        {
            if(weight[0]<=W)
            return values[0];
            else return 0;
        }
        if(dp[index][W]!=-1)return dp[index][W];
        int notpick = 0 + helper(index-1,weight,values,W,dp);
        int pick = INT_MIN;
        if(weight[index]<=W)
        pick = values[index] + helper(index-1,weight,values,W-weight[index],dp);
        
        return dp[index][W]= max(pick,notpick);
       
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        //vector<vector<int>>dp(n,vector<int>(W+1,-1));
       //return helper(n-1,wt,val,W,dp);

       vector<vector<int>>dp(n,vector<int>(W+1,0));
       //return helper(n-1,wt,val,W,dp);
       for(int i=wt[0];i<=W;i++)
       {
           dp[0][i]=val[0];
       }
       
       for(int index=1;index<n;index++)
       {
           for(int w=0;w<=W;w++)
           {
               int notpick = 0 + dp[index-1][w];
                int pick = INT_MIN;
                
                if(wt[index]<=w)
                pick = val[index] + dp[index-1][w-wt[index]];
                
                
                dp[index][w]=max(pick,notpick);
        
           }
       }
       return dp[n-1][W];
    }