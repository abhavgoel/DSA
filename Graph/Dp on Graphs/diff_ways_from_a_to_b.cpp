dp[n] = 0 for all n
dp[a]=1;

for(int i=0;i<topo.size();i++)
{
    int u = topo[i];
    for(auto v:graph[u])
    {
        dp[v]=dp[v]+dp[u];
    }
}
