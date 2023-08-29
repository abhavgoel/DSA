#include<bits/stdc++.h>
using namespace std;

//fails for negative weight edges,
//and fails for neative cycle

//works for positive cycle graphs

//O(ElogV)
//using priority queue because normal queue would go for all paths but the PQ will only continue on the shortest path
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>dist(V,1e9);
        dist[S]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,S});
        vector<int>vis(V,0);
        while(pq.empty()==false)
        {
            int d = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();

            if(vis[node] == 1)
            continue;

            vis[node]=1;
            
            for(auto i:adj[node])
            {
                int edgeWt=i[1];
                int adjNode=i[0];
                if(dist[node] + edgeWt < dist[adjNode])
                {
                    dist[adjNode] = edgeWt+dist[node];
                    pq.push({dist[adjNode],adjNode});
                }
                
                
            }
        }
        return dist;
    }

    //set approach------------------------------------------
    //it deletes a second less optimal path from the set
 vector <int> dijkstra1(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>dist(V,1e9);
        dist[S]=0;
        set<pair<int,int>>st;
        st.insert({0,S});
        
        while(st.empty()==false)
        {
            auto it = *(st.begin());//st.begin() pointer to first element, using * gives it value
            int node = it.second;
            int d= it.first;
            
            st.erase(it);
            
            for(auto i:adj[node])
            {
                int adjNode = i[0];
                int edgeWt=i[1];
                
                if(dist[node] + edgeWt < dist[adjNode])
                {
                    //erase if exist
                    if(dist[adjNode]!=1e9)
                    st.erase({dist[adjNode],adjNode});
                    
                    dist[adjNode] = dist[node] + edgeWt;
                    st.insert({dist[adjNode],adjNode});
                    
                }
            }
        }
        return dist;
        
    }