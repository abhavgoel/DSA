#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int helper(int i,int j1,int j2,int row,int col,vector<vector<int>>& grid, vector<vector<vector<int>>>&dp)
{
    if(j1<0||j2<0||j1>=col||j2>=col)
    return -1e8;

    if(i==row-1)
    {
        if(j1==j2)
        return grid[i][j1];//if same pick 1
        else
        return grid[i][j1] + grid[i][j2]; //else pick both
    }
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
    int maxi=-1e8;
    for(int dj1=-1;dj1<=1;dj1++)//possible column 1 motions
    {
        for(int dj2=-1;dj2<=1;dj2++)//possible column 1 motions
        {//total 9 combos
            int val=0;

            if(j1==j2) val = grid[i][j1];//if same pick 1
            else val = grid[i][j1]+grid[i][j2];//else both

            val+= helper(i+1,j1+dj1,j2+dj2,row,col,grid,dp);

            maxi=max(maxi,val);

        }
    }
    return dp[i][j1][j2] = maxi;

}
    int cherryPickup(vector<vector<int>>& grid) {
        int col=grid[0].size();
        int row=grid.size();
        //dp[row][col][col]
        vector<vector<vector<int>>>dp(row,vector<vector<int>>(col,vector<int>(col,0)));
        // return helper(0,0,col-1,row,col,grid,dp);


        //base case
        for(int j1=0;j1<col;j1++)
        {
            for(int j2=0;j2<col;j2++)
            {
                if(j1==j2)dp[row-1][j1][j2] = grid[row-1][j1];
                else dp[row-1][j1][j2] = grid[row-1][j1] + grid[row-1][j2];
            }
        }

        for(int i=row-2;i>=0;i--)
        {
            for(int j1=0;j1<col;j1++)
            {
                for(int j2=0;j2<col;j2++)
                {
                    int maxi=-1e8;

                    for(int dj1=-1;dj1<=1;dj1++)
                    {
                        for(int dj2=-1;dj2<=1;dj2++)
                        {
                            int val=0;

                            if(j1==j2) val = grid[i][j1];
                            else val = grid[i][j1]+grid[i][j2];

                            if(j1+dj1>=0 && j1+dj1<col && j2+dj2>=0 && j2+dj2<col )
                            val+= dp[i+1][j1+dj1][j2+dj2];

                            else
                            val+= -1e8;

                            maxi=max(maxi,val);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }

       

        return dp[0][0][col-1];

        
    }
};