#include<bits/stdc++.h>
using namespace std;
// a variation of nearest greater to left
int main()

{
    stack<pair<int,int>> s; //storing element as first and index as second
    vector<int> v;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];



    for(int i=0;i<n;i++)
    {
        if(s.size()==0)
        v.push_back(-1);

        else if(s.size()>0&&s.top().first>arr[i])
        v.push_back(s.top().second);

        else if(s.size()>0 && s.top().first<=arr[i])
        {
            while(s.size()>0 && s.top().first<=arr[i])
            s.pop();


            if(s.size()==0)
            v.push_back(-1);

            else
            v.push_back(s.top().second);

        }
        s.push({arr[i],i});
    }
    

    for(int i=0;i<n;i++)
    {
        v[i]=i-v[i];
    }
    for(auto i:v)
    cout<<i<<" ";
}