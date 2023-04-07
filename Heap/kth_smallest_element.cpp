#include<bits/stdc++.h>
using namespace std;

 int main()
 {
    priority_queue<int>pq;//max pq for smallest elements

    vector<int>arr{7,10,3,4,5,8};
    int n=arr.size();
    int k=3;

    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
        if(pq.size()>k)pq.pop();




    }
    cout<<pq.top();
}