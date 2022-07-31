#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    // cout<<q.front()<<" "<<q.back()<<endl;
    // q.pop();
    // cout<<q.front()<<" "<<q.back()<<endl;

    while(q.empty()==false)
    {
         cout<<q.front()<<" "<<q.back()<<endl;
         q.pop();
    }

    q.size();//for size

    return 0;
}