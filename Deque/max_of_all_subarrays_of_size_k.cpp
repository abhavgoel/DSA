#include<bits/stdc++.h>
using namespace std;

//naive approach

void printMax(int arr[],int n,int k)
{
    for(int i=0;i<n-k+1;i++)
    {
        int mx=arr[i];
        for(int j=i+1;j<i+k;j++)
        {
            mx=max(arr[j],mx);
        }
        cout<<mx<<" ";
    }
}

//optimised
vector<int> MaxOfAllSubarrays(int arr[],int n,int k)
{
    deque<int> dq;
    vector<int> v;
    int i=0;
    int j=0;
    while(j<n)
    {
        while(dq.size()>0 && dq.back()<arr[j])
        {
            dq.pop_back();
        }
        dq.push_back(arr[j]);

        if(j-i+1<k)
        j++;

        else if(j-i+1==k)
        {
            v.push_back(dq.front());
            if(dq.front()==arr[i])
            {
                dq.pop_front();
            }
            i++;
            j++;


        }
    }
    return v;


    
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int k;
    cin>>k;
    vector<int> v;
    v=MaxOfAllSubarrays(arr,n,k);
    for(auto i:v)
        cout<<i<<" ";
    
}

