#include<bits/stdc++.h>
using namespace std;

int main()
{
     stack<int> s;
    vector<int> v;

    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    cin>>arr[i];

    for(int i=n-1;i>=0;i--)
    {
        if(s.size()==0)
        v.push_back(-1);

        else if(s.size()>0 && s.top()<arr[i])
        v.push_back(s.top());

        else if(s.size()>0 && s.top()>=arr[i])
        {
            while(s.size()>0&&s.top()>=arr[i])
            s.pop();

            if(s.size()==0)
            v.push_back(-1);

            else
            v.push_back(s.top());

        }
        s.push(arr[i]);
    }
    reverse(v.begin(),v.end());

    for(auto i:v)
    cout<<i<<" ";
}