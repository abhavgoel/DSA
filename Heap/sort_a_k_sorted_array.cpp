#include<bits/stdc++.h>
using namespace std;

//element that should be at ith index is at i-k or i+k index range
    
vector <int> nearlySorted(vector<int>arr, int K){
    int num=arr.size();
    priority_queue<int,vector<int>,greater<int>> minh;
    vector<int> v;
    for(int i=0;i<num;i++)
    {
        minh.push(arr[i]);
        if(minh.size()>K)
        {
            v.push_back(minh.top());
            minh.pop();
        }
    }
    while(minh.size()>0)
        {
            v.push_back(minh.top());
            minh.pop();
        }
    return v;
}
