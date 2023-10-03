dp[n] = -INFINITY for all n
dp[a]=0;

for(int i=0;i<topo.size();i++)
{
    int u = topo[i];
    for(auto v:graph[u])
    {
        dp[v]=max(dp[v],dp[u]+1);
    }
}
