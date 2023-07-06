//SCC - STRONGLY connected components - in which every pair is is reachable both ways
//eg  - for pair (1,2)  we can go from 1->2 and from 2->1, then its a SCC
//KOSARAJU'S ALGO
//only for directed graphs


void dfs(int node,stack<int>&st,vector<int>&vis,vector<vector<int>>&adj)
	{
	    vis[node]=1;
	    for(auto it:adj[node])
	    {
	        if(vis[it]==0)
	        dfs(it,st,vis,adj);
	    }
	    st.push(node);
	}
	
	void dfs1(int node,vector<int>&vis,vector<vector<int>>&reverseGraph)
	{
	     vis[node]=1;
	    for(auto it:reverseGraph[node])
	    {
	        if(vis[it]==0)
	        dfs1(it,vis,reverseGraph);
	    }
	    
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int>st;
        //firstly we find the dfs traversal stack , the bottom elemebnt in the stack will be in the last SCC
        //and the first element would in the first scc
        
        //after that we reverse the edges to that the SCC's are separated , and we can run simple dfs to get the number of connected components, which would be the number of scc
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            dfs(i,st,vis,adj);
        }
        
        //now we have the stack filled - time to reverse the edges
        
        //we reverse the edges of the grpah
        
        vector<vector<int>>reverseGraph(V);
        
        for(int i=0;i<V;i++)
        {
            //i-->it
            for(auto it:adj[i])
            {
                reverseGraph[it].push_back(i);//it-->i
            }
        }
       vis=vector<int>(V,0);
        int scc=0;
        while(st.empty()==false)
        {
            int node = st.top();
            st.pop();
            if(vis[node]==0)
            {
                scc++;
                dfs1(node,vis,reverseGraph);
                
            }
        }
        return scc;
    }