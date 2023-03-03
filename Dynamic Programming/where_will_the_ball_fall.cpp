#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int helper(int i,int j,int m,int n,vector<vector<int>>& grid)
{
    if(j<0 || j>=n)
    return -1;

    if(i==m)return j;

    
    if(j+1<=n && grid[i][j]==1 && grid[i][j+1]==-1   )
    return -1;
    
    if(j-1>=0 && grid[i][j-1]==1 && grid[i][j]==-1 )
    return -1;
    

    if(grid[i][j]==1)
    return helper(i+1,j+1,m,n,grid);

    if(grid[i][j]==-1)
    return helper(i+1,j-1,m,n,grid);

    return -1;


}
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(n==1)return {-1};
        vector<int>ans;
        for(int j=0;j<n;j++)
        {
            ans.push_back(helper(0,j,m,n,grid));
        }
        return ans;

    }
};