#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {//depends on starting node
        vector<int>vis(V);
        queue<int>q;
        vector<int>ans;
        vis[0]=1;
        q.push(0);
        
        while(q.empty()==false)
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto i:adj[node])
            {
                if(!vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                }
            }
            
            
        }
        return ans;
    }