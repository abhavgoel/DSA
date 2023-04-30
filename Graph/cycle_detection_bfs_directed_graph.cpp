#include<bits/stdc++.h>
using namespace std;
//size of topo sort would be equal to number of nodes if graph is acyclic, else it would not be V
bool isCyclic(int V, vector<int> adj[]) {
       vector<int>indegree(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        indegree[it]++;
	    }
	    
	    queue<int>q;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    vector<int>topo;
	    while(q.empty()==false)
	    {
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto i:adj[node])
	        {
	            indegree[i]--;
	            if(indegree[i]==0)
	            {
	                q.push(i);
	            }
	        }
	    }
	    return topo.size()!=V;
    }