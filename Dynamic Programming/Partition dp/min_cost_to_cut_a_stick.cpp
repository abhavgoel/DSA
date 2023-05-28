#include<bits/stdc++.h>
using namespace std;

//we sort so that the subproblems are independent 
// eg 1,3,4,5,2 --->if we make a cut at  4 then the rob will be 1,2,3,4 and the for next sub
//problem the 2 will be present in first subproblem
//so we need to sort

class Solution {
public:
long long helper(int i,int j,vector<int>&cuts, vector<vector<int>>&dp)
{
    if(i>j)
    return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    long long mini=1e8;
    for(int ind=i;ind<=j;ind++)
    {
        long long cost=cuts[j+1]-cuts[i-1] 
        + helper(i,ind-1,cuts,dp) + helper(ind+1,j,cuts,dp);
        mini=min(mini,cost);
    }
    return dp[i][j] = mini;
}
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        // vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        
        // for(auto i:cuts)cout<<i<<" ";
        // return helper(1,c,cuts,dp);

        vector<vector<int>>dp(c+2,vector<int>(c+2,0));

        // i goes from 1->n....and j from n->1...so in tabulation order would be reversed

        for(int i=c;i>=1;i--)
        {
            for(int j=1;j<=c;j++)
            {
                if(i>j)continue;

                long long mini=1e8;
                for(int ind=i;ind<=j;ind++)
                {
                    long long cost=cuts[j+1]-cuts[i-1] 
                    + dp[i][ind-1] + dp[ind+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j] = mini;

            }
        }
        return dp[1][c];

    }
};