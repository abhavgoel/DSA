#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;//m=edges

    //undirected graph
    vector<vector<int>>adj(n+1);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);//remove this for directed graph
    }
}

//if graph is weigted the store pair of node and weight

