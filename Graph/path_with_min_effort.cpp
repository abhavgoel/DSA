#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<int>dx={0,0,1,-1};
vector<int>dy={1,-1,0,0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty())
        {
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(r==n-1 && c==m-1)
            return diff;

            for(int k=0;k<4;k++)    
            {
                int newr = r + dx[k];
                int newc = c + dy[k];

                if(newr>=0 && newc>=0 && newr<heights.size() && newc<heights[0].size())
                {
                    int effort = max(diff,abs(heights[r][c]-heights[newr][newc]));
                    if(effort<dist[newr][newc])
                    {
                        dist[newr][newc] = effort;
                        pq.push({dist[newr][newc],{newr,newc}});
                    }
                }
            }
        }
        return -1;
    }
};