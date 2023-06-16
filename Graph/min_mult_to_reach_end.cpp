#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int mod = 100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>>q;
        q.push({start,0});
        vector<int>dist(100000,1e9);
        while(q.empty()==false)
        {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(node==end)
            return steps;
            
            for(auto it:arr)
            {
                int num = (node*it) %mod;
                if(steps+1<dist[num])
                {
                    dist[num] = steps+1;
                    q.push({num,steps+1});
                }
            }
        }
        return -1;
    }
};