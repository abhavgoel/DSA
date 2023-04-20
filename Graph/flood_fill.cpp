#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};
    void dfs(int i,int j,int initcolor,int color,vector<vector<int>>&vis,vector<vector<int>>&ans)
    {
        if(i<0 || i>=ans.size() || j<0 || j>=ans[0].size() || 
        vis[i][j]==1 ||ans[i][j]!=initcolor)
        return;

        vis[i][j]=1;
        ans[i][j]=color;
        for(int k=0;k<4;k++)
        {
            dfs(i+dx[k],j+dy[k],initcolor,color,vis,ans);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
        int initcolor= image[sr][sc];
        dfs(sr,sc,initcolor,color,vis,ans);
        return ans;
    }
};