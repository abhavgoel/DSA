#include<bits/stdc++.h>
using namespace std;

// n nodes , m edges
 //matrix way

 //undirected graph

 int main()
 {
    int n;
    int m;
    cin>>n>>m;
    int adj[n+1][m+1]={0};//adjacency matrix
    for(int i=0;i<m;i++)//number of egdes
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;//if weighted graph replace with the weight
        adj[v][u]=1;//remove for directed graph
    }
 }