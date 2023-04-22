#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int sum= 0 ;

	for(int i:arr)sum+=i;

	int k = sum;


	vector<vector<bool>>dp(n , vector<bool>(k+1,0));
   

    //return helper(arr.size()-1,k,arr,dp);

    for(int i=0;i<n;i++)
    {
        dp[i][0]=true;
    }
    if(arr[0]<=k)
    dp[0][arr[0]]=true;

    for(int index=1;index<n;index++)
    {
        for(int target=1;target<=k;target++)
        {
             bool notpick = dp[index-1][target];
            bool pick = false;

            if(arr[index]<=target)
            pick =dp[index-1][target-arr[index]];

             dp[index][target] =  pick|notpick;
        }

    }
	int mini=1e8;
	for(int i=0;i<=sum/2;i++)
	{
		if(dp[n-1][i])
		{
			mini=min(mini,abs(sum-i)-i);
		}
	}
	return mini;
}
