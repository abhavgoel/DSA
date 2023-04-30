#include<bits/stdc++.h>
using namespace std;

//step -1 -> insert all nodes with indegree = 0 , as they wont have any node before them, so they can appear at the first of topo sort
//step - 2 -> take them out of the queue and minus the indegree of where they pount and if indegree 0 push further in the queue

vector<int> topoSort(int V, vector<int> adj[]) 
	{
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
	    return topo;
    }