#include<bits/stdc++.h>
using namespace std;

void sliding(int arr[],int n,int k)
{
    list<int> l;//deque
    vector<int>v;
    int i=0,j=0;
    while(j<n)
    {
        if(arr[j]<0)
            l.push_back(arr[j]);
        

            if(j-i+1<k)
                j++;

            else if(j-i+1==k)
            {
                if(l.size()==0)
                    v.push_back(0);
                
                else
                {
                    v.push_back(l.front());
                    if(arr[i]==l.front())
                        l.pop_front();
                    
                    i++;
                    j++;
                    
                }
            }

    }
     for(auto i:v)
     {
        cout<<i<<" ";
     }
     
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    // vector<int> vv;
    // vv=sliding(arr,n,k);
    // for(auto i:vv)
    // {
    //     cout<<i<<" ";
    // }
    sliding(arr,n,k);
}