#include<bits/stdc++.h>
using namespace std;
/*
Given a rod of length 'N' units.
 The rod can be cut into different sizes and each size has a cost associated with it. 
Determine the maximum cost obtained by cutting the rod and selling its pieces.*/

//1. The sizes will range from 1 to 'N' and will be integers.
//2. The sum of the pieces cut should be equal to 'N'
//3. Consider 1-based indexing.

int helper(int index,int target,vector<int>price,vector<vector<int>>&dp)
{
	if(index==0)
	return target * price[0];

	if(dp[index][target]!=-1)return dp[index][target];
	int notpick = 0 + helper(index-1,target,price,dp);
	int pick  = INT_MIN;
	int rodlength=index+1;
	if(rodlength<=target)
	pick = price[index] + helper(index,target-rodlength,price,dp);
	return dp[index][target] =  max(pick,notpick);
}

int cutRod(vector<int> &price, int n)
{
	//here n= target

	// a variation of unbounded knapsack

	// vector<vector<int>>dp(price.size(),vector<int>(n+1,-1));
	// return helper(price.size()-1,n,price,dp);
	vector<vector<int>>dp(price.size(),vector<int>(n+1,0));
	for(int t=0;t<=n;t++)
	{
		dp[0][t] = t*price[0];
	}
	for(int i=1;i<price.size();i++)
	{
		for(int t=0;t<=n;t++)
		{
			int notpick = 0 + dp[i-1][t];
			int pick  = INT_MIN;
			int rodlength=i+1;
			if(rodlength<=t)
			pick = price[i] + dp[i][t-rodlength];
			dp[i][t] =  max(pick,notpick);
		}
	}
	return dp[price.size()-1][n];


}
