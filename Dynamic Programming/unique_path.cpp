#include <bits/stdc++.h> 
using namespace std;
int helper(int row,int col)
{
	if(row==0&&col==0)
	{
		return 1;
	}

	if(row<0||col<0)
	return 0;

	int l = helper(row-1,col);

	int r = helper(row,col-1);

	return l+r;
}
int uniquePaths(int m, int n) {
	// Write your code here.

	return helper(m-1,n-1);
}

int uniquePathsTabulation(int m, int n) {
	// Write your code here.
	vector<vector<int>>dp(m,vector<int>(n,0));
		dp[0][0]=1;

		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==0 && j==0)continue;
				if (i > 0)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
                                
                        }
		}
		return dp[m-1][n-1];
}