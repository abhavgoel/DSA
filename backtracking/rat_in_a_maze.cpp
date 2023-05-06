#include<bits/stdc++.h>
using namespace std;

void helper(int i,int j,vector<vector<int>>&m,string moves,vector<string>&ans,int n,int dx[],int dy[])
    {
        // if(i<0||j<0||i>=n||j>=n||m[i][j]==0)
        // {
        //     return;
        // }
        
        if(i==n-1 && j==n-1)
        {
            ans.push_back(moves);
            moves="";
            return ;
        }
        
        string mm="DLRU";
        for(int ind=0;ind<4;ind++)
        {
            int nexti=i+dx[ind];
            int nextj=j+dy[ind];
            
            if(nexti<0||nextj<0||nexti>=n||nextj>=n||m[nexti][nextj]==0)
            return;
            
            // else
            // {
            m[i][j]=0;
            helper(nexti,nextj,m,moves+mm[ind],ans ,n,dx,dy);
            m[i][j]=1;
            //}
            
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        string moves="";
        if(m[0][0]==0)
        return {};
        
        int dx[4]={+1,0,0,-1};
        int dy[4]={0,-1,+1,0};
        helper(0,0,m,moves,ans,n,dx,dy);
        
        return ans;
    }