#include<bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        priority_queue<pair<int,int>>pq;//max heap bcoz we need min elements
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k)
            pq.pop();
        }

        while(pq.empty()==false)
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }