#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int main()
{
    vector<int>v;
    stack<int>s;

    int n;cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    cin>>arr[i];

    for(int i=0;i<n;i++)
    {
        if(s.size()==0)
        v.pb(-1);

        else if(s.size()>0 && s.top()>arr[i])
        v.pb(s.top());

        else if(s.size()>0 && s.top()<=arr[i])
        {
            while(s.size()>0 && s.top()<=arr[i])
            s.pop();

            if(s.size()==0)
            v.pb(-1);

            else
            v.pb(s.top());
        }
        s.push(arr[i]);
    }

    for(auto i:v)
    cout<<i<<" ";

}