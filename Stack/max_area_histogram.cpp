#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    // find the difference between nearest smaller right ans nearest smaller left

    vector<int> left(n);
    vector<int> right(n);

    stack<pair<int,int>>s;

    //nearest smaller left

    for(int i=0;i<n;i++)
    {
        if(s.size()==0)
        left[i]=-1;//pseudo index -1 for calculation of difference

        else if(s.size()>0 && s.top().first<arr[i])
        left[i]=(s.top().second);

        else if(s.size()>0 && s.top().first>=arr[i])
        {
            while(s.size()>0 && s.top().first>=arr[i])
            s.pop();

            if(s.size()==0)
            left[i]=-1;

            else left[i]=(s.top().second);
        }
        s.push({arr[i],i});
    }
    while(s.empty()==false)
    s.pop();
   
    //nearest smaller right
    for(int i=n-1;i>=0;i--)
    {
        if(s.size()==0)
        right[i]=n;

        else if(s.size()>0 && s.top().first<arr[i])
        right[i]=(s.top().second);

        else if(s.size()>0 && s.top().first>=arr[i])
        {
            while(s.size()>0 && s.top().first>=arr[i])
            s.pop();

            if(s.size()==0)
            right[i]=n;

            else right[i]=s.top().second;
        }
        s.push({arr[i],i});
    }
    //reverse(right.begin(),right.end());//using indexing method for vector so no reverse
    // for(auto i:right)
    // cout<<i<<" ";


    vector<int> width(n);
    for(int i=0;i<right.size();i++)
    {
        int x=right[i]-left[i]-1;
        width[i]=x;
    }
    vector<int>area(n);

    for(int i=0;i<n;i++)
    {
        area[i]=arr[i]*width[i];
    }

    cout<<*max_element(area.begin(),area.end());
}