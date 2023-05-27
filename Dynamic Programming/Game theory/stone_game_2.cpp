#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int helper(int i,int m,int turn,vector<int>&piles, vector<vector<vector<int>>>&dp)
{
    if(i>=piles.size())
    return 0;

    int result;
    if(turn==0)
    result = -1e9;
    else
    result = 1e9;

    if(dp[i][m][turn]!=-1)return dp[i][m][turn];
    int stones=0;
    for(int x=1;x<=min(2*m,(int)piles.size()-i);x++)
    {
        stones += piles[i+x-1];//to calc sum for multiple indices
        if(turn==0)
        {
            result = max(result,stones + helper(i+x,max(x,m),1,piles,dp));
        }
        else if(turn==1)
        {
            result = min(result,helper(i+x,max(x,m),0,piles,dp));
        }
    }
    return dp[i][m][turn] = result;
}
    int stoneGameII(vector<int>& piles) {
        //turn = 0 for alice
        //turn = 1 for BoB
        int n = piles.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2*n,vector<int>(2,-1)));
        
        return helper(0,1,0,piles,dp);
        
    }
};