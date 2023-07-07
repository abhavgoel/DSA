class Solution {
public:
int timer=1;
vector<vector<int>>bridges;
void dfs(int node,int parent , vector<int>&vis,vector<vector<int>>&graph,vector<int>&tin,vector<int>&low)
{
    vis[node]=1;
    tin[node] = low[node] = timer;
    timer++;

    for(auto it:graph[node])
    {
        if(it==parent)continue;

        if(vis[it]==0)
        {
            dfs(it,node,vis,graph,tin,low);
            low[node] = min(low[it],low[node]);

            //node -->it
            if(low[it]>tin[node])
            bridges.push_back({node,it});
        }
        else//if visited , just take the low value
        {
            low[node] = min(low[node],low[it]);//there is a back edge that means , that node can also be reached via some different path...so not a bridge
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>graph(n);
        for(int i=0;i<connections.size();i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);

        }

        vector<int>tin(n,0);
        vector<int>low(n,0);
        vector<int>vis(n,0);
        // vector<vector<int>>bridges;

        dfs(0,-1,vis,graph,tin,low);;

        return bridges;
    }
};