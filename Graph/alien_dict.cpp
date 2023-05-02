#include<bits/stdc++.h>
using namespace std;

vector<int>topoSort(vector<vector<int>>&graph,int V)
    {
        vector<int>indegree(V,0);
        vector<int>topo;
        
        for(int i=0;i<V;i++)
        {
            for(auto it:graph[i])
            {
                indegree[it]++;
            }
        }
        queue<int>q;
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        
        while(q.empty()==false)
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto i:graph[node])
            {
                indegree[i]--;
                if(indegree[i]==0)
                q.push(i);
            }
            
        }
        return topo;
    }
    string findOrder(string dict[], int N, int K) {
        // we need to create a graph from the strings, the graph should have nodes that come before
        //the next node....like for "baa" and "abcd"...its clear 'b comes before 'a'
        //so make a edge from b->a
        //for this we initialize a pointer at starting of both strings, and when the characters are not equal
        //its time to create a edge at the inequality
        
        vector<vector<int>>graph(K);
        //----------this code block creates the graph--------------------
        for(int i=0;i<N-1;i++)
        {
            string s1=dict[i];
            string s2= dict[i+1];
            int len = min(s1.size(),s2.size());
            
            for(int j=0;j<len;j++)
            {
                if(s1[j]!=s2[j])
                {
                    graph[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        //now we just need to apply topological sort to get the order of characters
        vector<int>topo = topoSort(graph,K);
        string ans="";
        for(auto i:topo)
        {
            ans=ans + char(i+'a');  
        }
        return ans;
        
        
        
    }