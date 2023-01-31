#include<bits/stdc++.h>
using namespace std;
void insert(stack<int>&s,int val)
{
    if(s.size()==0){
    s.push(val);
    return;
    }

    int temp=s.top();
    s.pop();
    insert(s,val);
    s.push(temp);
}
void solve(stack<int>&s)
{
    if(s.size()==1)
    return ;

    int val=s.top();
    s.pop();
    solve(s);
    insert(s,val);
}

int main()
{
    stack<int>s;

    for(int i=0;i<5;i++)
    {
        int a;
        cin>>a;
        s.push(a);
    }

    int k= (s.size()/2) + 1;

    solve(s);

    while(s.empty()==false)
    {
        cout<<s.top();
        s.pop();
    }
}