#include<bits/stdc++.h>
using namespace std;


// [ Assume u have topologically sorted nodes in a DAG, in vector topo ]

dp[n] = INFINITY for all n
dp[a]=0;

// In topological order
// dp[i] represent the min distance to reach node i
for(int i=0; i<topo.size(); i++)
{
    int u = topo[i];
    for(auto v:graph[u]) 
    {
        dp[v] = min(dp[v],dp[u]+1);
    }  
}
cout<<dp[b];

