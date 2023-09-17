#include <bits/stdc++.h> 
int allVis;

int helper(int i,int mask,vector<vector<int>> &distance,vector<vector<int>>&dp)
{
	if (mask==allVis)
	return distance[i][0];

	
	if(dp[i][mask]!=-1)
	return dp[i][mask];

	int ans=INT_MAX;

	for(int city = 0;city<distance.size();city++)
	{
		if((mask & (1<<city)))//already visited
		continue;

		int newMask = mask | (1<<city);

		int tourCost = distance[i][city] + helper(city,newMask,distance,dp);

		ans=min(ans,tourCost);

	}

	return dp[i][mask]=ans;
}
int shortestRoute(vector<vector<int>> &distance)
{
	int n = distance.size();
	allVis = (1<<n)-1;
	vector<vector<int>>dp(n,vector<int>(allVis+1,-1));

	return helper(0,1,distance,dp);


}
