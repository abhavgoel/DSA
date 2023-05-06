#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isSafe(int row,int col,vector<string>board,int n)
    {
        //we have to only check for striaght left, upper left diagonal
        //ans lower left diagonal
        
        int duprow=row;
        int dupcol=col;
        
        //checking upper left
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            
            col--;
            row--;
        }
        
        //checking straight left
        
        col=dupcol;
        row=duprow;
        while(col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            
            col--;
        }
        
        //lower left
        col=dupcol;
        row=duprow;
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            
            row++;
            col--;
        }
        return true;
    }
    int helper(int col,vector<string>&board,vector<vector<string>>&ans,int n)
    {
        if(col==n)
        {
            return 1;
                
        }
        int count=0;
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col]='Q';
                count=count + helper(col+1,board,ans,n);
                board[row][col]='.';
            }
            
        }
        return count;
        
    }
    int totalNQueens(int n) {
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            
            board[i]=s;
        }
        vector<vector<string>>ans;
        
        return helper(0,board,ans,n);
        
    }
};