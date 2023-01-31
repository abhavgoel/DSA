#include<bits/stdc++.h>
using namespace std;
void solve(stack<int>&s,int k)
{
    if(k==1)
    {
        s.pop();
        return;

    }
    int val=s.top();
    s.pop();

    solve(s,k-1);
    s.push(val);

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

    solve(s,k);

    while(s.empty()==false)
    {
        cout<<s.top();
        s.pop();
    }
}