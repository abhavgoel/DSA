#include<bits/stdc++.h>
using namespace std;

//shortest path via every node
void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==-1)
	            matrix[i][j]=1e9;
	            
	            if(i==j)
	            matrix[i][j]=0;
	        }
	    }
	    
	    for(int k=0;k<n;k++)//calculating shortest path via every node
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }
	    
	    for(int i=0;i<n;i++)//distance from node to itself will be updated to negative if negative cycle is present
	    {
	        if(matrix[i][i]<0)
	        cout<<"negative cycle"<<endl;
	    }
	    
	     for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==1e9)
	            matrix[i][j]=-1;
	           
	        }
	    }
	}