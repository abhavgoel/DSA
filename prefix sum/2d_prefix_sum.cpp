#include<bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
vector<vector<int>>prefix;
    NumMatrix(vector<vector<int>>& matrix) {
       
        int n=matrix.size();
        int m=matrix[0].size();
         prefix.resize(n,vector<int>(m));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                prefix[i][j]=matrix[i][j];
                if(i-1>=0)prefix[i][j]+=prefix[i-1][j];
                if(j-1>=0)prefix[i][j]+=prefix[i][j-1];
                if(i-1>=0 && j-1>=0)prefix[i][j]-=prefix[i-1][j-1];
                cout<<prefix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2][col2]-prefix[row1-1][col2]-prefix[row2][col1-1]+prefix[row1-1][col1-1];
    }
};