#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<string,vector<pair<string,double>>>&graph,string &src,string &dst, unordered_set<string>&vis,double product,double &ans)
    {
        if(vis.find(src)!=vis.end())
        return;

        vis.insert(src);
        if(src==dst)
        {
            ans=product;
            return;
        }
        for(auto i:graph[src])
        {
            string s=i.first;
            double val = i.second;
            dfs(graph,s,dst,vis,product*val,ans);
        }


    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();

        unordered_map<string,vector<pair<string,double>>>graph;

        for(int i=0;i<n;i++)
        {
            string u =equations[i][0];
            string v = equations[i][1];

            double val = values[i];

            graph[u].push_back({v,val});
            graph[v].push_back({u,1.0/val});

        }

        vector<double>result;

        for(auto q:queries)
        {
            string src=q[0];
            string dst=q[1];

            double ans=-1.0;
            double product=1.0;

            if(graph.find(src)!=graph.end() && graph.find(dst)!=graph.end())
            {
                unordered_set<string>vis;
                dfs(graph,src,dst,vis,product,ans);
            }
            result.push_back(ans);
            
        }
        return result;
    }
};