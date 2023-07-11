class Solution {
    
    public:
    // the idea is that if the low of adjacent node is greater than or equal to the current node, then current node is 
    //an articulation point

    vector<int>arti;
    int timer = 1;
    
    void dfs(int node , int parent,vector<int>&vis,vector<int>&tin,vector<int>&low,vector<int>adj[])
    {
        vis[node]=1;
        int child=0;
        tin[node] = low[node] = timer;
        timer++;
        
        for(auto it:adj[node])
        {
            if(it==parent)continue;
            
            if(vis[it]==0)
            {
                dfs(it,node,vis,tin,low,adj);
                low[node] = min(low[node],low[it]);
                
                if(low[it]>=tin[node] && parent!=-1)
                {
                    arti[node]=1;
                }
                child++;
            }
            else low[node] = min(low[node],tin[it]);//we take the discovery time of node , 
            //bcoz if that node is to be removed we cant reach previous nodes that
            // come before it,bcoz it is gonna be removed....so discovery time not lowest time
        }
        if(child>1&&parent==-1)
        arti[node]=1;
    }
  public:
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int>tin(V,0);
        vector<int>low(V,0);
        vector<int>vis(V,0);
        arti.resize(V);
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            dfs(i,-1,vis,tin,low,adj);
        }
        
        for(int i=0;i<V;i++)
        {
            if(arti[i]==1)
            ans.push_back(i);
        }
        if(ans.size()==0)return {-1};
        return ans;
    }
};