#include<bits/stdc++.h>
using namespace std;


int main()
{
    deque<int> dq={10,20,30};
    dq.push_front(5);
    dq.push_back(15);
    for(auto x:dq)
    cout<<x<<" ";
    cout<<endl;

    cout<<dq.front()<<" "<<dq.back()<<endl;

    deque<int> dqq={1,2,3,4};
    auto it=dqq.begin();
    it++;

    dqq.insert(it,20);//adds value before the iterator
    for(auto x:dqq)
    cout<<x<<" ";
    cout<<endl;
    dqq.pop_front();
    dqq.pop_back();
    cout<<dqq.size()<<endl;

}