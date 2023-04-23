#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//the intuition is to traverse the board's top row bottom row, leftmost column and rightmost column
//and apply a traversal algorithm on all 'O' found in these rows and columns and marking them as visited...finally marking the O in orignal board which are not marked.

//becasue the 'O' connected to other 'O' in the board on boundaries could never be enclosed by a 'X'
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};

    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&board)
    {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='X'||vis[i][j]==1)
        return;


        vis[i][j]=1;
        for(int k=0;k<4;k++)
        {
            dfs(i+dx[k],j+dy[k],vis,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            if(vis[i][0]==0 && board[i][0]=='O')//first column
            dfs(i,0,vis,board);

            if(vis[i][m-1]==0 && board[i][m-1]=='O')//last column
            dfs(i,m-1,vis,board);
        }

        for(int j=0;j<m;j++)
        {
            if(vis[0][j]==0 && board[0][j]=='O')//first row
            dfs(0,j,vis,board);

            if(vis[n-1][j]==0 && board[n-1][j]=='O')//last row
            dfs(n-1,j,vis,board); 
        }

        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && board[i][j]=='O')
                board[i][j]='X';
            }
        }
        
    }
};