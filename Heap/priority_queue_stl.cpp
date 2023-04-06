#include<bits/stdc++.h>
using namespace std;

//max heap priority queue

void maxPq()
{
    priority_queue<int>pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);

    cout<<pq.top()<<" "<<endl;

    cout<<pq.size()<<endl;

    while(pq.empty()==false)
    {
        cout<<pq.top()<<" ";
        pq.pop();

    }
}

//min heap priority queue
void minPq()
{
    priority_queue<int,vector<int>,greater<int>>pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);

    cout<<pq.top()<<" "<<endl;

    cout<<pq.size()<<endl;

    while(pq.empty()==false)
    {
        cout<<pq.top()<<" ";
        pq.pop();

    }
}
int main(){
    maxPq();
    cout<<endl;
    minPq();
}