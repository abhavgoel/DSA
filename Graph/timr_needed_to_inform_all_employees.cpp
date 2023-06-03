#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
       
        vector<vector<int>>graph(n);
        
        for(int i=0;i<n;i++)
        {
            if(manager[i]==-1)continue;
            graph[manager[i]].push_back(i);
        }

        queue<pair<int,int>>q;
        q.push({headID,informTime[headID]});
        int time=0;
        while(q.empty()==false)
        {
            int node = q.front().first;
            int t = q.front().second;
            time = max(t,time);

            q.pop();

            for(auto i:graph[node])
            {
                q.push({i,t + informTime[i]});
            }
        }
        return time;

    }
};